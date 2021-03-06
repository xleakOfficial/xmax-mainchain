/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <unordered_map>
#include <pro/io/file_system.hpp>
#include <apps.hpp>
#include <pluginface.hpp>



namespace xmaxapp
{
	namespace bpo = boost::program_options;

	/**
	* Application instance. 
	* Use for Application and Plugin System.
	*/
	class Application : public ApplicationBase
	{
	public:
		Application();
		virtual ~Application();

		/**
		* Get the app service interface.
		* @return App service interface.
		*/
		virtual AppService* GetService() const override;

		/**
		* Get data dir.
		* @return data dir.
		*/
		virtual fs::path GetDataDir() const override;

		/**
		* find plugin by name
		* @return plugin
		*/
		virtual Plugin* FindPlugin(const string& name) const override;
		/**
		* get plugin by name
		* @return plugin
		*/
		virtual Plugin& GetPlugin(const string& name) const override;

		/**
		* Register plugin to the application
		* @template param: plugin class
		*/
		template <class PluginType>
		void RegisterPlugin(bool inital = false) {
			PluginType::RegistSelf();
			PluginToInit(PluginType::PluginName());
			if (inital)
			{
				InitalPlugin<PluginType>();
			}
		}

		/**
		* Set inital plugin.
		* @param[in] plugin_name plugin name.
		*/
		void InitalPlugin(const string& plugin_name);

		/**
		* Set inital plugin.
		* @param[in] PluginType plugin type.
		*/
		template <class PluginType>
		void InitalPlugin() {
			InitalPlugin(PluginType::PluginName());
		}

		/**
		* Init a concrete plugin
		* @param[in] argc number of args
		* @param[in] argv the content of params
		*/
		bool Initialize(int argc, char** argv);
		/**
		*	start the app
		*/
		void Startup();
		/**
		*	shutdown the app
		*/
		void Shutdown();
		/**
		*	Main loop of the logic
		*/
		void Loop();
		/**
		*	quit the app
		*/
		void Quit();


		//==============Utility methods ============

		void SetDefaultConfigFilePath(const fs::path& path) { cfg_file_path_ = path; }

	private:

		void PluginToInit(const string& plugin_name);

		void SetupApplicationOptions();
		
		/**
		* Load all the options supported in the configuration file
		* @param[out] option variable map storing the option values
		*/
		void LoadCfgOptions(bpo::variables_map& var_map);

		/**
		*	Create default configuration file
		*/
		void CreateDefaultCfgFile();

	private:
		std::set<std::string> initalplugins_;
		std::unordered_map<string, std::unique_ptr<PluginFace>>	pluginmap_;
		std::vector<PluginFace*>						initialized_plugins_;
		std::vector<PluginFace*>						startup_plugins_;

		OptionsDesc     app_options_;
		OptionsDesc     cfg_options_;

		fs::path cfg_file_path_;
		fs::path data_dir_{ "data-dir" };


		std::unique_ptr<AppService>  service_face_;	
	};


}

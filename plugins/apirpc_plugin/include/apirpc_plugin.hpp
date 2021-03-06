/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <pluginface.hpp>


namespace xmax
{
	using xmaxapp::OptionsDesc;
	using xmaxapp::VarsMap;
	
	class ApiRpcPluginImpl;

	using UrlHandlerResult = std::optional<std::tuple<int /*status*/, std::string /*body*/>>;
	using UrlHandler = std::function<UrlHandlerResult(std::string_view /*url*/, std::string_view /*req*/)>;
	

/*!
 * \class ApiRPCPlugin
 * \brief The builder plugin use for build logic.
 */
	class ApiRpcPlugin : public xmaxapp::PluginFace
	{
		GENERATED_PLUGIN(ApiRpcPlugin, xmaxapp::PluginFace, &InitOptions)

	public:
		ApiRpcPlugin();
		virtual ~ApiRpcPlugin();

		// xmaxapp::PluginFace interface ----------------------------------
		virtual void Initialize(const VarsMap& options) override;
		virtual void Startup() override;
		virtual void Shutdown() override;
			
		// ----------------------------------------------------------------
		void AddUrlHandler(std::string_view url, UrlHandler handler);

	protected:


		static void InitOptions(OptionsDesc& cli, OptionsDesc& cfg);		
		


		std::unique_ptr<ApiRpcPluginImpl> impl_;
	};
}

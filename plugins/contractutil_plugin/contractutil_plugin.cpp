#include <contractutil_plugin.hpp>

namespace xmax {
	using namespace xmaxapp;

	/**
	*  Implementation details of the contract util plugin
	*
	*/
	class ContractUtilPluginImpl {
	public:
		ContractUtilPluginImpl() {}
		~ContractUtilPluginImpl();
	};

	/**
	*  Implementations of ContractUtilPluginImpl interfaces
	*
	*/
	ContractUtilPluginImpl::~ContractUtilPluginImpl()
	{
	}

	/**
	*  Implementations of ContractUtilPlugin interfaces
	*
	*/
	//--------------------------------------------------
	ContractUtilPlugin::ContractUtilPlugin() {
		// TODO : initialize members
	}

	//--------------------------------------------------
	ContractUtilPlugin::~ContractUtilPlugin() {
		Clean();
	}

	//--------------------------------------------------
	void ContractUtilPlugin::Initialize(const xmaxapp::VarsMap& options) {

		PluginFace::Initialize(options);

		impl_.reset(new ContractUtilPluginImpl());

		// test initialize code 
		Test("init");
	}

	//--------------------------------------------------
	void ContractUtilPlugin::Startup() {
		PluginFace::Startup();
		
		// TODO : setup all 
	}

	//--------------------------------------------------
	void ContractUtilPlugin::Shutdown() {
		impl_.reset();

		PluginFace::Shutdown();
	}

	//--------------------------------------------------
	void ContractUtilPlugin::Test(const char* log) {
		printf("test a log");
	}

	//--------------------------------------------------
	void ContractUtilPlugin::Clean()
	{
		printf("clean");
	}

	//-------------------------------------------------
	void ContractUtilPlugin::CreateContract()
	{
		// create contract
		printf("create contract {}");
	}
}

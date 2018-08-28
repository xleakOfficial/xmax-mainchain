/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <pluginface.hpp>
#include <chain.hpp>


namespace xmax
{
	using xmaxapp::OptionsDesc;

	class BlockChainPlugin : public xmaxapp::PluginFace
	{
		GENERATED_PLUGIN(BlockChainPlugin, xmaxapp::PluginFace, &InitOptions)
	public:

		virtual void Startup() override;


		chain::IChainContext* GetChain() const;
	protected:
		static void InitOptions(OptionsDesc& cli, OptionsDesc& cfg);

	protected:
		std::unique_ptr<chain::IChainContext> context_;
	};
}
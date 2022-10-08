#include "Test.h"
#include "../Settings.h"
#include "../Proj/Project.h"

#include <Files/File.h>
#include <Logging/Logger.h>
#include <Util/Xml/ReflectedDocument.h>

#include <rapidxml_ext.hpp>
#include <rapidxml_print.hpp>
#include <rapidxml_utils.hpp>

#include <iterator>
#include <iostream>
#include <filesystem>

using namespace Common;
using namespace Common::Files;
using namespace Common::Logging;
using namespace Common::Logging::Logger;
using namespace Common::Mod;
using namespace Common::Util;
using namespace Common::Util::Xml;
using namespace DevKit;
using namespace DevKit::Features;
using namespace DevKit::Proj;
namespace fs = std::filesystem;

Test::Test() : Feature("test", "Test the NKHook5 MDK") {

}

std::string Test::ActivatorArgs() {
	return "-t, --test";
}

bool Test::FlagOnly()
{
	return true;
}

void Test::Run(std::vector<std::string> args) {
	nlohmann::json& settings = Settings::ReadSettings();

	std::string modName = args[0];
	std::string resultPath;
	if (args.size() > 1) {
		resultPath = args[1];
	}

	fs::path cwd = fs::current_path();
	fs::path modPath = cwd / modName;
	if (!fs::exists(modPath)) {
		Print(LogLevel::ERR, "No such mod '%s'", modName.c_str());
		return;
	}

	Project modProj;
	modProj.Open(modName);
	fs::path modDir = modProj.GetModPath();
	fs::path modTextureDir = modDir / "Textures";
	fs::path vanillaDir = modProj.GetVanillaPath();
	fs::path vanillaTextureDir = vanillaDir / "Textures";

	fs::path reflectPath = modTextureDir / "SpriteInfo.rxml";

	File reflectFile(reflectPath);
	std::string reflectXml = reflectFile.ReadStr();

	fs::path spriteXmlPath = vanillaTextureDir / "SpriteInfo.xml";

	File spriteXmlFile(spriteXmlPath);
	std::string spriteXml = spriteXmlFile.ReadStr();

	ReflectedDocument refl(reflectXml);
	rapidxml::xml_document<>* spriteXmlDoc = new rapidxml::xml_document<>();
	spriteXmlDoc->parse<0>((char*)spriteXml.c_str());
	refl.Reflect(spriteXmlDoc);

	std::string finalXml;
	rapidxml::internal::print_node(std::back_inserter(finalXml), spriteXmlDoc, 0, 0);
	printf("%s", finalXml.c_str());
}
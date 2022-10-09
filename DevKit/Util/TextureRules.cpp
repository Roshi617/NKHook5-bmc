#include "TextureRules.h"

using namespace DevKit;
using namespace DevKit::Util;

CompileResult::CompileResult(std::string quality, std::string texture, std::string infoXml)
{
	this->quality = quality;
	this->texture = texture;
	this->infoXml = infoXml;
}

CompileResult::CompileResult(nlohmann::json document)
{
	this->quality = document["Quality"];
	this->texture = document["Texture"];
	this->infoXml = document["InfoXml"];
}

const std::string& CompileResult::GetQuality() const
{
	return this->quality;
}

const std::string& CompileResult::GetTexture() const
{
	return this->texture;
}

const std::string& CompileResult::GetInfoXml() const
{
	return this->infoXml;
}

Compile::Compile(std::string sourceDir, std::vector<CompileResult> results)
{
	this->sourceDir = sourceDir;
	this->results = results;
}

Compile::Compile(nlohmann::json document)
{
	nlohmann::json sourceDir = document["SourceDir"];
	if (!sourceDir.is_string()) {
		throw std::exception("Compile expected SourceDir to be a string, but it was not.");
	}

	this->sourceDir = sourceDir;

	nlohmann::json results = document["Results"];
	if (!results.is_array()) {
		throw std::exception("Compile expected Results to be a list, but it was not.");
	}

	std::vector<CompileResult> result;
	for (auto& r : results) {
		result.emplace_back(r);
	}

	this->results = result;
}

const std::string& Compile::GetSourceDir() const
{
	return this->sourceDir;
}

const std::vector<CompileResult>& Compile::GetResults() const
{
	return this->results;
}

TextureRules::TextureRules(std::vector<std::string> reflections, std::vector<Compile> compiles)
{
	this->reflections = reflections;
	this->compiles = compiles;
}

TextureRules::TextureRules(nlohmann::json document)
{
	nlohmann::json reflections = document["Reflections"];
	if (!reflections.is_array()) {
		throw std::exception("TextureRules expected Reflections to be a list, but it was not.");
	}

	std::vector<std::string> reflectsVec;
	for (auto& reflect : reflections) {
		reflectsVec.emplace_back(reflect);
	}

	nlohmann::json compiles = document["Compiles"];
	if (!compiles.is_array()) {
		throw std::exception("TextureRules expected Compiles to be a list, but it was not.");
	}

	std::vector<Compile> compilesVec;
	for (auto& compile : compiles) {
		compilesVec.emplace_back(compile);
	}

	this->reflections = reflectsVec;
	this->compiles = compilesVec;
}

const std::vector<std::string>& TextureRules::GetReflects() const
{
	return this->reflections;
}

const std::vector<Compile>& TextureRules::GetCompiles() const
{
	return this->compiles;
}

//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/main/extension_entries.cpp
//
//===----------------------------------------------------------------------===//

#include "duckdb/main/extension_entries.hpp"

namespace duckdb {

const DuckDBExtensionEntriesV1 &ExtensionEntries::Get() {
	return *duckdb_extension_entries_v1();
}

const char *ExtensionEntries::DefaultExtensionDirectories() {
	return Get().default_extension_directories;
}

const ExtensionEntry *ExtensionEntryCollection::data() const {
	auto &entries = ExtensionEntries::Get();
	switch (kind) {
	case ExtensionEntryKind::SETTINGS:
		return entries.settings;
	case ExtensionEntryKind::SECRET_TYPES:
		return entries.secret_types;
	case ExtensionEntryKind::COPY_FUNCTIONS:
		return entries.copy_functions;
	case ExtensionEntryKind::TYPES:
		return entries.types;
	case ExtensionEntryKind::COLLATIONS:
		return entries.collations;
	case ExtensionEntryKind::FILE_PREFIXES:
		return entries.file_prefixes;
	case ExtensionEntryKind::FILE_POSTFIXES:
		return entries.file_postfixes;
	case ExtensionEntryKind::FILE_CONTAINS:
		return entries.file_contains;
	case ExtensionEntryKind::SECRET_PROVIDERS:
		return entries.secret_providers;
	}
	return nullptr;
}

idx_t ExtensionEntryCollection::size() const {
	auto &entries = ExtensionEntries::Get();
	switch (kind) {
	case ExtensionEntryKind::SETTINGS:
		return entries.settings_count;
	case ExtensionEntryKind::SECRET_TYPES:
		return entries.secret_types_count;
	case ExtensionEntryKind::COPY_FUNCTIONS:
		return entries.copy_functions_count;
	case ExtensionEntryKind::TYPES:
		return entries.types_count;
	case ExtensionEntryKind::COLLATIONS:
		return entries.collations_count;
	case ExtensionEntryKind::FILE_PREFIXES:
		return entries.file_prefixes_count;
	case ExtensionEntryKind::FILE_POSTFIXES:
		return entries.file_postfixes_count;
	case ExtensionEntryKind::FILE_CONTAINS:
		return entries.file_contains_count;
	case ExtensionEntryKind::SECRET_PROVIDERS:
		return entries.secret_providers_count;
	}
	return 0;
}

const ExtensionEntry *ExtensionEntryCollection::begin() const {
	return data();
}

const ExtensionEntry *ExtensionEntryCollection::end() const {
	return data() + size();
}

const ExtensionEntry &ExtensionEntryCollection::operator[](idx_t index) const {
	return data()[index];
}

const ExtensionFunctionEntry *ExtensionFunctionEntryCollection::data() const {
	return ExtensionEntries::Get().functions;
}

idx_t ExtensionFunctionEntryCollection::size() const {
	return ExtensionEntries::Get().functions_count;
}

const ExtensionFunctionEntry *ExtensionFunctionEntryCollection::begin() const {
	return data();
}

const ExtensionFunctionEntry *ExtensionFunctionEntryCollection::end() const {
	return data() + size();
}

const ExtensionFunctionEntry &ExtensionFunctionEntryCollection::operator[](idx_t index) const {
	return data()[index];
}

const ExtensionFunctionOverloadEntry *ExtensionFunctionOverloadEntryCollection::data() const {
	return ExtensionEntries::Get().function_overloads;
}

idx_t ExtensionFunctionOverloadEntryCollection::size() const {
	return ExtensionEntries::Get().function_overloads_count;
}

const ExtensionFunctionOverloadEntry *ExtensionFunctionOverloadEntryCollection::begin() const {
	return data();
}

const ExtensionFunctionOverloadEntry *ExtensionFunctionOverloadEntryCollection::end() const {
	return data() + size();
}

const ExtensionFunctionOverloadEntry &ExtensionFunctionOverloadEntryCollection::operator[](idx_t index) const {
	return data()[index];
}

const char *const *AutoloadableExtensionCollection::data() const {
	return ExtensionEntries::Get().autoloadable_extensions;
}

idx_t AutoloadableExtensionCollection::size() const {
	return ExtensionEntries::Get().autoloadable_extensions_count;
}

const char *const *AutoloadableExtensionCollection::begin() const {
	return data();
}

const char *const *AutoloadableExtensionCollection::end() const {
	return data() + size();
}

const char *AutoloadableExtensionCollection::operator[](idx_t index) const {
	return data()[index];
}

} // namespace duckdb

/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_CHARACTER_MEMMED_SPELLS_REPOSITORY_H
#define EQEMU_BASE_CHARACTER_MEMMED_SPELLS_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>

class BaseCharacterMemmedSpellsRepository {
public:
	struct CharacterMemmedSpells {
		uint32_t id;
		uint16_t slot_id;
		uint16_t spell_id;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"slot_id",
			"spell_id",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"slot_id",
			"spell_id",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("character_memmed_spells");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static CharacterMemmedSpells NewEntity()
	{
		CharacterMemmedSpells e{};

		e.id       = 0;
		e.slot_id  = 0;
		e.spell_id = 0;

		return e;
	}

	static CharacterMemmedSpells GetCharacterMemmedSpells(
		const std::vector<CharacterMemmedSpells> &character_memmed_spellss,
		int character_memmed_spells_id
	)
	{
		for (auto &character_memmed_spells : character_memmed_spellss) {
			if (character_memmed_spells.id == character_memmed_spells_id) {
				return character_memmed_spells;
			}
		}

		return NewEntity();
	}

	static CharacterMemmedSpells FindOne(
		Database& db,
		int character_memmed_spells_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {} = {} LIMIT 1",
				BaseSelect(),
				PrimaryKey(),
				character_memmed_spells_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			CharacterMemmedSpells e{};

			e.id       = row[0] ? static_cast<uint32_t>(strtoul(row[0], nullptr, 10)) : 0;
			e.slot_id  = row[1] ? static_cast<uint16_t>(strtoul(row[1], nullptr, 10)) : 0;
			e.spell_id = row[2] ? static_cast<uint16_t>(strtoul(row[2], nullptr, 10)) : 0;

			return e;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int character_memmed_spells_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				character_memmed_spells_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		const CharacterMemmedSpells &e
	)
	{
		std::vector<std::string> v;

		auto columns = Columns();

		v.push_back(columns[0] + " = " + std::to_string(e.id));
		v.push_back(columns[1] + " = " + std::to_string(e.slot_id));
		v.push_back(columns[2] + " = " + std::to_string(e.spell_id));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", v),
				PrimaryKey(),
				e.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static CharacterMemmedSpells InsertOne(
		Database& db,
		CharacterMemmedSpells e
	)
	{
		std::vector<std::string> v;

		v.push_back(std::to_string(e.id));
		v.push_back(std::to_string(e.slot_id));
		v.push_back(std::to_string(e.spell_id));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", v)
			)
		);

		if (results.Success()) {
			e.id = results.LastInsertedID();
			return e;
		}

		e = NewEntity();

		return e;
	}

	static int InsertMany(
		Database& db,
		const std::vector<CharacterMemmedSpells> &entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &e: entries) {
			std::vector<std::string> v;

			v.push_back(std::to_string(e.id));
			v.push_back(std::to_string(e.slot_id));
			v.push_back(std::to_string(e.spell_id));

			insert_chunks.push_back("(" + Strings::Implode(",", v) + ")");
		}

		std::vector<std::string> v;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<CharacterMemmedSpells> All(Database& db)
	{
		std::vector<CharacterMemmedSpells> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterMemmedSpells e{};

			e.id       = row[0] ? static_cast<uint32_t>(strtoul(row[0], nullptr, 10)) : 0;
			e.slot_id  = row[1] ? static_cast<uint16_t>(strtoul(row[1], nullptr, 10)) : 0;
			e.spell_id = row[2] ? static_cast<uint16_t>(strtoul(row[2], nullptr, 10)) : 0;

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static std::vector<CharacterMemmedSpells> GetWhere(Database& db, const std::string &where_filter)
	{
		std::vector<CharacterMemmedSpells> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterMemmedSpells e{};

			e.id       = row[0] ? static_cast<uint32_t>(strtoul(row[0], nullptr, 10)) : 0;
			e.slot_id  = row[1] ? static_cast<uint16_t>(strtoul(row[1], nullptr, 10)) : 0;
			e.spell_id = row[2] ? static_cast<uint16_t>(strtoul(row[2], nullptr, 10)) : 0;

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, const std::string &where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int64 GetMaxId(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COALESCE(MAX({}), 0) FROM {}",
				PrimaryKey(),
				TableName()
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

	static int64 Count(Database& db, const std::string &where_filter = "")
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COUNT(*) FROM {} {}",
				TableName(),
				(where_filter.empty() ? "" : "WHERE " + where_filter)
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

};

#endif //EQEMU_BASE_CHARACTER_MEMMED_SPELLS_REPOSITORY_H

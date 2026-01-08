meta:
  id: hs_profsav
  file-extension: hs_prof.sav
  title: FTL Hyperspace Profile File
  encoding: UTF-8
  endian: le
  license: MIT
  ks-version: '0.10'
  imports: []

doc: |
  FTL (Faster Than Light) Hyperspace Achievement Profile Save File Format.

  File Format Version: 4-9 (vanilla), 3 (Hyperspace extensions)
  Endianness: Little-Endian
  String Encoding: 4-byte length prefix + UTF-8 data

  This format extends the original FTL ae_prof.sav format with 4 additional
  data blocks for Hyperspace mod functionality:
  - Block 1: Custom Ship Unlocks
  - Block 2: Custom Achievements
  - Block 3: Custom Ship Scores
  - Block 4: Meta Variables

seq:
  # ========== VANILLA FTL DATA (ae_prof.sav format) ==========
  - id: version
    type: s4
    doc: File format version (4-9 for vanilla format compatibility)

  - id: opened_list
    type: s4
    doc: Bitfield of opened ship layouts

  - id: achievements
    type: achievement_block
    doc: Vanilla achievement data

  # ========== HYPERSPACE EXTENSION DATA ==========
  - id: hyperspace_save_extension
    type: hyperspace
  # ========== END HYPERSPACE ==============

  - id: ship_unlocks
    type: ship_unlocks
    doc: Vanilla ship unlock status (12 ship slots)

  - id: top_scores
    type: score_block
    doc: Top scores across all ships

  - id: ship_scores
    type: score_block
    doc: Per-ship high scores

  - id: lifetime_stats
    type: lifetime_stats_block
    doc: 4 lifetime statistics (ships defeated, beacons, scrap, crew hired)

  - id: games_played
    type: s4
    doc: Total games played count

  - id: victories
    type: s4
    doc: Total victories count

  - id: crew_stats
    type: crew_stats
    doc: 5 crew statistic records


types:
  # ========== VANILLA FTL TYPES ==========

  len_str:
    seq:
      - id: length
        type: u4
        doc: String length in bytes
      - id: data
        type: str
        encoding: UTF-8
        size: length
        doc: UTF-8 encoded string data

  achievement_block:
    seq:
      - id: length
        type: s4
        doc: Number of achievement entries
      - id: entries
        type: achievement
        repeat: expr
        repeat-expr: length

  achievement:
    seq:
      - id: name
        type: len_str
        doc: Achievement ID/name
      - id: difficulty_or_value
        type: s4
        doc: Progress value or difficulty level
      - id: ship_difficulties
        type: ship_difficulties
        if: is_victory
        doc: Present only for victory achievements

    instances:
      is_victory:
        # ends-with "VICTORY" (covers both "..._VICTORY" and "...VICTORY")
        value: name.data.length >= 7 and name.data.substring(name.data.length - 7, name.data.length) == "VICTORY"

  ship_difficulties:
    seq:
      - id: layout_a
        type: s4
        enum: ship_layout_difficulty
      - id: layout_b
        type: s4
        enum: ship_layout_difficulty
      - id: layout_c
        type: s4
        enum: ship_layout_difficulty

  score_block:
    seq:
      - id: length
        type: s4
        doc: Number of score entries
      - id: entries
        type: ship_score
        repeat: expr
        repeat-expr: length

  ship_score:
    seq:
      - id: ship_name
        type: len_str
        doc: Captain/ship name
      - id: blueprint
        type: len_str
        doc: Ship blueprint ID (e.g., "PLAYER_SHIP_HARD")
      - id: final_score
        type: s4
        doc: Final score achieved
      - id: sector_reached
        type: s4
        doc: Highest sector number reached
      - id: victory_flag
        type: s4
        enum: bool
        doc: 1 if victory achieved, 0 otherwise
      - id: difficulty
        type: s4
        enum: difficulty
        doc: Game difficulty level
      - id: advanced_content
        type: s4
        enum: bool
        doc: DLC enabled flag

  lifetime_stats_block:
    seq:
      - id: ships_defeated
        type: lifetime_stat
      - id: beacon
        type: lifetime_stat
      - id: scrap
        type: lifetime_stat
      - id: crew_hired
        type: lifetime_stat

  lifetime_stat:
    seq:
      - id: max_single
        type: s4
        doc: Best single-game achievement
      - id: accumulated_total
        type: s4
        doc: Total across all games

  ship_unlocks:
    seq:
      - id: player_ship_hard
        type: ship_unlock_layout
        doc: Kestrel (index 0)
      - id: player_ship_stealth
        type: ship_unlock_layout
        doc: Stealth (index 1)
      - id: player_ship_mantis
        type: ship_unlock_layout
        doc: Mantis (index 2)
      - id: player_ship_circle
        type: ship_unlock_layout
        doc: Engi (index 3)
      - id: player_ship_fed
        type: ship_unlock_layout
        doc: Federation (index 4)
      - id: player_ship_jelly
        type: ship_unlock_layout
        doc: Slug (index 5)
      - id: player_ship_rock
        type: ship_unlock_layout
        doc: Rock (index 6)
      - id: player_ship_energy
        type: ship_unlock_layout
        doc: Zoltan (index 7)
      - id: player_ship_crystal
        type: ship_unlock_layout
        doc: Crystal (index 8)
      - id: player_ship_anaerobic
        type: ship_unlock_layout
        doc: Lanius (index 9)
      - id: reserved_10
        type: ship_unlock_layout
        doc: Reserved slot 10
      - id: reserved_11
        type: ship_unlock_layout
        doc: Reserved slot 11

  ship_unlock_layout:
    seq:
      - id: layout_a
        type: s4
        enum: bool
        doc: Layout A unlocked status
      - id: layout_c
        type: s4
        enum: bool
        doc: Layout C unlocked status
      # Note: Layout B unlock is determined at load time from achievement state

  crew_stats:
    seq:
      - id: most_repairs_performed
        type: crew_stat
      - id: most_combat_kills
        type: crew_stat
      - id: most_piloted_evasions
        type: crew_stat
      - id: most_jumps_survived
        type: crew_stat
      - id: most_skills_mastered
        type: crew_stat

  crew_stat:
    seq:
      - id: best_value
        type: s4
        doc: The statistic value achieved
      - id: name
        type: len_str
        doc: Crew member's name
      - id: species
        type: len_str
        doc: Species/race (e.g., "human", "mantis")
      - id: male
        type: s4
        enum: bool
        doc: Gender flag

  # ========== HYPERSPACE EXTENSION TYPES ==========
  hyperspace:
    seq:
      - id: custom_ship_unlocks
        type: custom_ship_unlocks_block
        doc: Hyperspace custom ship unlock data

      - id: custom_achievements
        type: custom_achievements_block
        doc: Hyperspace custom achievement data. NOTE only in version 3 which is stored IN A SEPARATE hs_version.sav file ugh...

      - id: custom_ship_scores
        type: custom_ship_scores_block
        doc: Hyperspace custom ship score data

      - id: meta_variables
        type: meta_variables_block
        doc: Hyperspace meta variables for achievement tracking. NOTE only in version 3 which is stored IN A SEPARATE hs_version.sav file ugh...
    types:
      custom_ship_unlocks_block:
        # 1. customUnlockedShips: vector<string>
        seq:
          - id: ships
            type: custom_ship_array

          # 2. customUnlockQuestShips: unordered_map<string, int>
          # Key: ship blueprint name, Value: difficulty level
          - id: quest_ships
            type: custom_difficulty_ship_array

          # 3. shipVictories: unordered_map<string, int>
          # Key: ship blueprint name, Value: difficulty level achieved
          - id: ship_victories
            type: custom_difficulty_ship_array

          # 4. customShipVictories: unordered_map<string, unordered_map<string, int>>
          # Nested structure for different victory types (flagship, custom)
          - id: custom_ship_victories
            type: custom_ship_victories

        types:
          custom_ship_victories:
            seq:
              - id: count
                type: s4
                doc: Number of victory type categories
              - id: category
                type: custom_victory_type
                repeat: expr
                repeat-expr: count
                doc: Per-victory-type ship achievements
          custom_ship_array:
            seq:
              - id: count
                type: s4
                doc: Number of custom unlocked ships
              - id: ship_blueprint
                type: len_str
                repeat: expr
                repeat-expr: count
                doc: Custom ship blueprint names
          custom_difficulty_ship_array:
            seq:
              - id: count
                type: s4
                doc: Number of custom unlocked ships
              - id: ships
                type: difficulty_ship_entry
                repeat: expr
                repeat-expr: count
                doc: Custom ship blueprint names
          custom_victory_type:
            seq:
              - id: victory_type
                type: len_str
                doc: Victory type name (e.g., "chaos", "peace", "flagship", "slug", "riggerfs", "commonwealth", "true", "aea_old_win", "nexus")
              - id: ship_victories
                type: custom_difficulty_ship_array
                doc: Ship victories for this victory type
          difficulty_ship_entry:
            seq:
              - id: ship_blueprint
                type: len_str
                doc: Ship blueprint name
              - id: difficulty
                type: s4
                enum: difficulty
                doc: Difficulty achieved (-1=unset, 0=easy, 1=normal, 2=hard)

      custom_achievements_block:
        seq:
          - id: count
            type: s4
            doc: Number of custom achievement entries
          - id: entries
            type: achievement_unlock_entry
            repeat: expr
            repeat-expr: count
            doc: Custom achievement unlock status per difficulty
        types:
          achievement_unlock_entry:
            seq:
              - id: achievement_id
                type: len_str
                doc: Achievement name ID
              - id: difficulty
                enum: difficulty
                type: s4
                doc: Unlock difficulty (-1=locked, 0=easy, 1=normal, 2=hard)

      custom_ship_scores_block:
        seq:
          - id: count
            type: s4
            doc: Number of ships with custom scores
          - id: entries
            type: custom_ship_score_entry
            repeat: expr
            repeat-expr: count
            doc: Custom ship high scores (max 4 per ship)
        types:
          custom_ship_score_entry:
            seq:
              - id: ship_blueprint
                type: len_str
                doc: Ship blueprint name
              - id: scores
                type: score_block
                doc: Custom ship scores
      meta_variables_block:
        seq:
          - id: count
            type: s4
            doc: Number of meta variables
          - id: entries
            type: var_entry
            repeat: expr
            repeat-expr: count
        types:
          var_entry:
            seq:
              - id: name
                type: len_str
              - id: value
                type: s4

enums:
  ship_layout_difficulty:
    -1: unset
    0: easy
    1: normal
    2: hard

  difficulty:
    0: easy
    1: normal
    2: hard

  bool:
    0: false
    1: true

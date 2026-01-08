meta:
  id: ae_profsav
  file-extension: ae_prof.sav
  title: FTL Achievement Profile File
  encoding: UTF-8
  endian: le
  license: MIT
  ks-version: '0.10'
  imports: []

doc: |
  FTL (Faster Than Light) Achievement Profile Save File Format.
  
  File Format Version: 4-9
  Endianness: Little-Endian
  String Encoding: 4-byte length prefix + UTF-8 data

seq:
  - id: version
    type: s4

  - id: opened_list
    type: s4

  - id: achievements
    type: achievement_block

  - id: ship_unlocks
    type: ship_unlocks
    
  - id: top_scores
    type: score_block
    
  - id: ship_scores
    type: score_block

  - id: lifetime_stats
    type: lifetime_stats_block

  - id: games_played
    type: s4

  - id: victories
    type: s4
    
  - id: crew_stats
    type: crew_stats

types:
  achievement_block:
    seq:
      - id: length
        type: s4
      - id: entries
        type: achievement
        repeat: expr
        repeat-expr: length
      
  score_block:
    seq:
      - id: length
        type: s4
      - id: entries
        type: ship_score
        repeat: expr
        repeat-expr: length

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
      - id: accumulated_total
        type: s4

  len_str:
    seq:
      - id: length
        type: u4
      - id: data
        type: str
        encoding: UTF-8
        size: length
        
  ship_unlocks:
    seq:
      - id: player_ship_hard        # index 0
        type: ship_unlock_layout
      - id: player_ship_stealth     # index 1
        type: ship_unlock_layout
      - id: player_ship_mantis      # index 2
        type: ship_unlock_layout
      - id: player_ship_circle      # index 3
        type: ship_unlock_layout
      - id: player_ship_fed         # index 4
        type: ship_unlock_layout
      - id: player_ship_jelly       # index 5
        type: ship_unlock_layout
      - id: player_ship_rock        # index 6
        type: ship_unlock_layout
      - id: player_ship_energy      # index 7
        type: ship_unlock_layout
      - id: player_ship_crystal     # index 8
        type: ship_unlock_layout
      - id: player_ship_anaerobic   # index 9
        type: ship_unlock_layout
      - id: reserved_10             # index 10
        type: ship_unlock_layout
      - id: reserved_11             # index 11
        type: ship_unlock_layout


  achievement:
    seq:
      - id: name
        type: len_str
      - id: difficulty_or_value
        type: s4
      - id: ship_difficulties
        type: ship_difficulties
        if: is_victory

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
  
  ship_unlock_layout:
    seq:
      - id: layout_a
        type: s4
        enum: bool
      - id: layout_c
        type: s4
        enum: bool
        # Note layout b unlock is determined at load time from the achievement state (ForceUnlock checks for _QUEST and _VICTORY IDs) so no dedicated flag is stored for it... this is actually chaos subset, what the heck.


  ship_score:
    seq:
      - id: ship_name
        type: len_str
      - id: blueprint
        type: len_str
      - id: final_score
        type: s4
      - id: sector_reached
        type: s4
      - id: victory_flag
        type: s4
        enum: bool
      - id: difficulty
        type: s4
        enum: difficulty
      - id: advanced_content # a.k.a. DLC enabled
        type: s4
        enum: bool
        
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
      - id: best_value # or the value achieved by this specific crew member in regards to the stat named
        type: s4
      - id: name
        type: len_str
      - id: species
        type: len_str
      - id: male # unsure if this is actually "gender" or if the statistic is new and just unviewed yet (needs testing)
        type: s4
        enum: bool
        
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

# instances:
#   is_supported_version:
#     value: version >= 4 and version <= 9
#   ship_scores_count_per_layout:
#     value: ship_scores_total_count / 3
#   total_achievements:
#     value: achievements.size
#   total_top_scores:
#     value: top_scores.size
#   total_ship_scores:
#     value: ship_scores_a.size + ship_scores_b.size + ship_scores_c.size
#   crew_stats_count:
#     value: crew_stats.size

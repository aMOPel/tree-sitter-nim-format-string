#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 12
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 9
#define ALIAS_COUNT 1
#define TOKEN_COUNT 4
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym__everything_else = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  sym_source_file = 4,
  sym_string_content = 5,
  sym_matching_curlies = 6,
  aux_sym_string_content_repeat1 = 7,
  aux_sym_matching_curlies_repeat1 = 8,
  alias_sym_everything_else_inside = 9,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__everything_else] = "_everything_else",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_source_file] = "source_file",
  [sym_string_content] = "string_content",
  [sym_matching_curlies] = "matching_curlies",
  [aux_sym_string_content_repeat1] = "string_content_repeat1",
  [aux_sym_matching_curlies_repeat1] = "matching_curlies_repeat1",
  [alias_sym_everything_else_inside] = "everything_else_inside",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__everything_else] = sym__everything_else,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_source_file] = sym_source_file,
  [sym_string_content] = sym_string_content,
  [sym_matching_curlies] = sym_matching_curlies,
  [aux_sym_string_content_repeat1] = aux_sym_string_content_repeat1,
  [aux_sym_matching_curlies_repeat1] = aux_sym_matching_curlies_repeat1,
  [alias_sym_everything_else_inside] = alias_sym_everything_else_inside,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__everything_else] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_string_content] = {
    .visible = true,
    .named = true,
  },
  [sym_matching_curlies] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_string_content_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_matching_curlies_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_everything_else_inside] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [1] = alias_sym_everything_else_inside,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym_matching_curlies_repeat1, 2,
    aux_sym_matching_curlies_repeat1,
    alias_sym_everything_else_inside,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      if (lookahead == '{') ADVANCE(5);
      if (lookahead == '}') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 1:
      if (lookahead == '}') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 2:
      if (eof) ADVANCE(3);
      if (lookahead == '{') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym__everything_else);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 2},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__everything_else] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(10),
    [sym_string_content] = STATE(11),
    [sym_matching_curlies] = STATE(2),
    [aux_sym_string_content_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__everything_else] = ACTIONS(5),
    [anon_sym_LBRACE] = ACTIONS(7),
  },
  [2] = {
    [sym_matching_curlies] = STATE(3),
    [aux_sym_string_content_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym__everything_else] = ACTIONS(11),
    [anon_sym_LBRACE] = ACTIONS(7),
  },
  [3] = {
    [sym_matching_curlies] = STATE(3),
    [aux_sym_string_content_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym__everything_else] = ACTIONS(15),
    [anon_sym_LBRACE] = ACTIONS(18),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(21), 1,
      sym__everything_else,
    ACTIONS(23), 1,
      anon_sym_RBRACE,
    STATE(6), 1,
      aux_sym_matching_curlies_repeat1,
  [10] = 2,
    ACTIONS(27), 1,
      sym__everything_else,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
  [18] = 3,
    ACTIONS(21), 1,
      sym__everything_else,
    ACTIONS(29), 1,
      anon_sym_RBRACE,
    STATE(8), 1,
      aux_sym_matching_curlies_repeat1,
  [28] = 2,
    ACTIONS(33), 1,
      sym__everything_else,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
  [36] = 3,
    ACTIONS(35), 1,
      sym__everything_else,
    ACTIONS(38), 1,
      anon_sym_RBRACE,
    STATE(8), 1,
      aux_sym_matching_curlies_repeat1,
  [46] = 2,
    ACTIONS(40), 1,
      sym__everything_else,
    ACTIONS(42), 1,
      anon_sym_RBRACE,
  [53] = 1,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
  [57] = 1,
    ACTIONS(46), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 10,
  [SMALL_STATE(6)] = 18,
  [SMALL_STATE(7)] = 28,
  [SMALL_STATE(8)] = 36,
  [SMALL_STATE(9)] = 46,
  [SMALL_STATE(10)] = 53,
  [SMALL_STATE(11)] = 57,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_content, 1),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_content_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_content_repeat1, 2), SHIFT_REPEAT(3),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_content_repeat1, 2), SHIFT_REPEAT(4),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_matching_curlies, 2),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_matching_curlies, 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_matching_curlies, 3, .production_id = 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_matching_curlies, 3, .production_id = 1),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_matching_curlies_repeat1, 2), SHIFT_REPEAT(9),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_matching_curlies_repeat1, 2),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_matching_curlies_repeat1, 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_matching_curlies_repeat1, 1),
  [44] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nim_format_string(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif

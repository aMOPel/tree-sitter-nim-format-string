module.exports = grammar({
  name: 'nim_format_string',

  extras: $ => [
    /[\n\r\s]+/,
  ],

  rules: {
    source_file: $ => optional($.string_content),
    string_content: $ => repeat1(choice($.matching_curlies, $._everything_else)),
    _everything_else: $ => /[^\n\r\s]/,
    matching_curlies: $ => seq(
      '{',
      alias(repeat($._everything_else), $.everything_else_inside),
      '}',
    ),
  }
});

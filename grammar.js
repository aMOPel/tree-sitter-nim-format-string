module.exports = grammar({
  name: 'nim_format_string',

  extras: _ => [
    /[\n\r\s]+/,
  ],

  rules: {
    source_file: $ => optional($.string_literal),
    string_literal: $ => repeat1(choice($.matching_curlies, $._everything_else, $.double_curlies)),
    matching_curlies: $ => seq(
      field('opening_curly', $.opening_curly),
      field('nim_expression', alias(repeat1(choice(
        /[^:={}\n\r\s]/,
        field('escaped_curly', $.escaped_curly,),
      )), $.nim_expression)),
      optional(field('equals', $.equals)),
      optional(field('format_specifiers', $.format_specifiers)),
      field('closing_curly', $.closing_curly),
    ),

    format_specifiers: $ => seq(
      field('colon', $.colon),
      optional(field('fill_align', $.fill_align)),
      optional(field('sign', $.sign)),
      optional(field('hash', $.hash)),
      optional(field('zero', $.zero)),
      optional(field('min_width', $.min_width)),
      optional(field('precision', $.precision)),
      optional(field('type', $.type)),
    ),

    _everything_else: _ => /[^{}\n\r\s]/,
    double_curlies: _ => choice('{{', '}}'),
    escaped_curly: _ => choice('\\{', '\\}'),
    opening_curly: _ => '{',
    closing_curly: _ => '}',
    equals: _ => '=',

    colon: _ => ':',
    // NOTE: `[^{}<\^>]` is not according to spec but otherwise things break
    // BUG: the fill char can't be <space>, collision with $.sign
    fill_align: _ => token.immediate(/[^{}<\^>\n\r]?[<\^>]/),
    sign: _ => token.immediate(/[\-+ ]/),
    hash: _ => token.immediate('#'),
    zero: _ => token.immediate('0'),
    min_width: _ => token.immediate(/[1-9][0-9]*/),
    precision: _ => token.immediate(/\.[1-9][0-9]*/),
    type: _ => token.immediate(/[bdoxXeEfFgG]/),
  }
});

# tree-sitter-nim-format-string

[tree-sitter](https://github.com/tree-sitter/tree-sitter) 
parser for format strings in stdlib 
([std/strformat](https://nim-lang.org/docs/strformat.html)) 
in [Nim](https://github.com/nim-lang/Nim).

This parser can be injected when using `&` or `fmt` templates from 
[std/strformat](https://nim-lang.org/docs/strformat.html).

Inside the string, in the `{...}` (the `(nim_expression)` node),
the normal [Nim parser](https://github.com/alaviss/tree-sitter-nim)
can be injected again to then parse the nim expression 
inside the curlies. So this is just a small utility parser.

Examples:

```nim
import std/strformat

let x = "World"
discard &"Hello {x}!"
discard fmt"Hello {x}!"
discard fmt"""
Hello 
{
x & x
}
!
"""
```

### Limitations

**1.**
There are known issues (in NeoVim) with injection and overwriting of highlights.
This is particularly noticable with multiline strings, where some of the nim expressions
will still be highlighted the same as the surrounding string.

**2.**
In format strings inside the curlies, `{` and `}` have to be escaped.
Consider a set literal:

```nim
# double curlies in format strings are just escapes single curlies
echo fmt"a{{'b'..'y'}}z" # prints "a{b..y}z"
# to write a set you need \{ \}
echo fmt"a{\{'b'..'y'\}}z" 
# prints a{'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}z
```

The problem is that `\{`/`\}` are not normal nim syntax,
which breaks the injected `Nim parser`.
thus expressions in format strings containing `\{`/`\}` will intentionally 
not be parsed.

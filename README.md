# echolor

Yeah, ANSI colors are cool and all, but I think using a more human-readable command would be more appropriate.

`echolor [STRING] [OPTIONS]`

## Supported colors

|long   |short|comments        |
|-------|-----|----------------|
|black  |bk   |                |
|red    |r    |                |
|green  |g    |                |
|yellow |y    |                |
|blue   |bl   |                |
|purple |p    |                |
|magenta|m    |Alias for purple|
|cyan   |c    |                |
|white  |w    |                |

- The foreground color is applied with the `-c` option.
- The background color applied with `-b` option

## Supported styles

|long     |short|comments         |
|---------|-----|-----------------|
|regular  |r    |                 |
|normal   |n    |Alias for regular|
|bold     |b    |                 |
|underline|u    |                 |

- the style is applied with the `-s` option

## exemple

To display the string "Hello planet Earth" in highlighted green underline with a cyan background,

`echolor "Hello planet Earth" -c=g -s=u -b=c -fh`

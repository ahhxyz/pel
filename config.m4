PHP_ARG_ENABLE(pel, whether to enable pel support,
[  --enable-pel           Enable pel support])

if test "$PHP_PEL" != "no"; then
  PHP_NEW_EXTENSION(pel, pel.c, $ext_shared)
fi

lib_LTLIBRARIES = libFrugalosErasurecode_rs_vand.la

# liberasurecode_rs_vand params
libFrugalosErasurecode_rs_vand_la_SOURCES = rs_galois.c liberasurecode_rs_vand.c
libFrugalosErasurecode_rs_vand_la_CPPFLAGS = -I$(top_srcdir)/include/rs_vand @GCOV_FLAGS@

# Version format  (C - A).(A).(R) for C:R:A input
libFrugalosErasurecode_rs_vand_la_LDFLAGS = @GCOV_LDFLAGS@ -rpath '$(libdir)' -version-info 1:1:0

MOSTLYCLEANFILES = *.gcda *.gcno *.gcov

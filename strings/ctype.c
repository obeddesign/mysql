/* Copyright (C) 2000 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#include <my_global.h>
#include <m_ctype.h>
#ifndef SCO
#include <m_string.h>
#endif

/* generated by make, using conf_to_src */
#include "ctype_extra_sources.c"

/* generated by configure */
#include "ctype_autoconf.c"

CHARSET_INFO *default_charset_info = &compiled_charsets[0];

CHARSET_INFO *find_compiled_charset(uint cs_number)
{
  CHARSET_INFO *cs;
  for (cs = compiled_charsets; cs->number > 0; cs++)
    if (cs->number == cs_number)
      return cs;

  return NULL;
}

CHARSET_INFO *find_compiled_charset_by_name(const char *name)
{
  CHARSET_INFO *cs;
  for (cs = compiled_charsets; cs->number > 0; cs++)
    if (!strcmp(cs->name, name))
      return cs;

  return NULL;
}

uint compiled_charset_number(const char *name)
{
  CHARSET_INFO *cs;
  for (cs = compiled_charsets; cs->number > 0; cs++)
    if (!strcmp(cs->name, name))
      return cs->number;

  return 0;   /* this mimics find_type() */
}

const char *compiled_charset_name(uint charset_number)
{
  CHARSET_INFO *cs;
  for (cs = compiled_charsets; cs->number > 0; cs++)
    if (cs->number == charset_number)
      return cs->name;

  return "?";   /* this mimics get_type() */
}

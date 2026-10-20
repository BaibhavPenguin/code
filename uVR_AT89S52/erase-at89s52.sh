#!/bin/sh
CONF=/etc/avrdude.conf
PART=AT89S52
PROG=usbasp
BLCK=10

avrdude \-C "$CONF" \-c "$PROG" \-p "$PART" \-B "$BLCK" \-e

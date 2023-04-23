#!/bin/sh

curl https://www.iana.org/assignments/dns-parameters/dns-parameters-6.csv -o rcodes.csv || exit 1

echo '#pragma once' > dns-rcodes.h
echo >> dns-rcodes.h

echo "/* Built from IANA online data at $(date '+%Y-%m-%d %H:%M:%S %z') */" >> dns-rcodes.h
echo >> dns-rcodes.h

tr -d '\n' < rcodes.csv | tr '\r' '\n' | sed 's/        //' | \
sed -En 's@^([0-9]+),([^,"]+),([^,]+),(.*)$@#define DNS_RCODE_\2 \1 \/* \3 \4 *\/@p' \
>> dns-rcodes.h

echo '#define DNS_rcode_RESERVED 65535 /* Can be allocated by Standards Action [RFC6895] */' >> dns-rcodes.h

rm -f rcodes.csv

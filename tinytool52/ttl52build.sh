#!/bin/bash
if [ -z "$1" ]; then
    echo "Error : No Config Selected!"
    echo "List of available configurations are"
    cat "${PWD}/config/configlists.txt"
    exit 1
fi

conf=$1
source "${PWD}/config/${conf}"

cd "${source}" && echo "${filename} selected , Changing directory..."

for file in **/*.c; do
    [ -e "$file" ] || continue
    sdcc -"${target}" -"${memory_model}" -c "${file}" -o "${output}"
done

echo "Cleaning up generated objects, *.rel files preseved"
echo "Deleted *.sym & *.lst"
echo "Assembly Files & Object Files moved to respective locations"
mv -f "${output}"*.asm "${assembly}"
rm -f "${output}"*.sym  "${output}"*.lst


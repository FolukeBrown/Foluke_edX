#!/bin/bash

BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"
BETTY_WRAPPER="betty"

APP_PATH="/opt/betty"
BIN_PATH="/usr/local/bin"
MAN_PATH="/usr/local/share/man/man1"

echo -e "Uninstalling binaries.."

rm "${APP_PATH}/${BETTY_STYLE}"
rm "${APP_PATH}/${BETTY_DOC}"
rm "${APP_PATH}/${BETTY_WRAPPER}"

rm "${BIN_PATH}/${BETTY_STYLE}"
rm "${BIN_PATH}/${BETTY_DOC}"
rm "${BIN_PATH}/${BETTY_WRAPPER}"

rm -r "${APP_PATH}"

echo -e "Uninstalling man pages.."

rm -r "${MAN_PATH}"
rm -r "${MAN_PATH}"
rm -r "${MAN_PATH}"

rm -r "${MAN_PATH}"

echo -e "Updating man database.."

mandb

echo -e "Done."

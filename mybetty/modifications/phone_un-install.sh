#!/bin/bash

BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"
BETTY_WRAPPER="phone_betty"

APP_PATH="$PREFIX/opt/betty"
BIN_PATH="$PREFIX/bin"
MAN_PATH="$PREFIX/share/man/man1"
echo -e "APP_PATH, BIN_PATH, MAN_PATH"
echo -e "$APP_PATH"
echo -e "$BIN_PATH"
echo -e "$MAN_PATH"

echo -e "Uninstalling binaries.."

echo -e "APP_PATH"
echo -e "$(pwd)"
echo -e "$APP_PATH"

rm "${APP_PATH}/${BETTY_STYLE}"
rm "${APP_PATH}/${BETTY_DOC}"
rm "${APP_PATH}/${BETTY_WRAPPER}"

echo -e "BETTY_STYLE, BETTY_DOC, BETTY_WRAPPER"
echo -e "$BETTY_STYLE"
echo -e "$BETTY_DOC"
echo -e "$BETTY_WRAPPER"

rm "${BIN_PATH}/${BETTY_STYLE}"
rm "${BIN_PATH}/${BETTY_DOC}"
rm "${BIN_PATH}/${BETTY_WRAPPER}"

rm -r "${APP_PATH}"

echo -e "Uninstalling man pages.."

echo -e "MAN_PATH"
echo -e "$(pwd)"
echo -e "$MAN_PATH"

rm -r "${MAN_PATH}"
rm -r "${MAN_PATH}"
rm -r "${MAN_PATH}"

rm -r "${MAN_PATH}"

echo -e "Done."

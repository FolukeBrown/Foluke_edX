#!/bin/bash

BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"
BETTY_WRAPPER="phone_betty"

echo ""
APP_PATH="$PREFIX/opt/betty"
BIN_PATH="$PREFIX/bin"
MAN_PATH="$PREFIX/share/man/man1"
echo -e "APP_PATH, BIN_PATH, MAN_PATH"
echo -e "$APP_PATH"
echo -e "$BIN_PATH"
echo -e "$MAN_PATH"

echo ""
echo -e "Installing binaries.."

mkdir -p "${APP_PATH}"
echo -e "APP_PATH"
echo -e "$(pwd)"
echo -e "$APP_PATH"

cp "${BETTY_STYLE}.pl" "${APP_PATH}/${BETTY_STYLE}"
cp "${BETTY_DOC}.pl" "${APP_PATH}/${BETTY_DOC}"
cp "${BETTY_WRAPPER}.sh" "${APP_PATH}/${BETTY_WRAPPER}"

chmod +x "${APP_PATH}/${BETTY_STYLE}"
chmod +x "${APP_PATH}/${BETTY_DOC}"
chmod +x "${APP_PATH}/${BETTY_WRAPPER}"
echo ""
echo -e "BETTY_STYLE, BETTY_DOC, BETTY_WRAPPER"
echo -e "$BETTY_STYLE"
echo -e "$BETTY_DOC"
echo -e "$BETTY_WRAPPER"

echo ""
ln -s "${APP_PATH}/${BETTY_STYLE}" "${BIN_PATH}/${BETTY_STYLE}"
ln -s "${APP_PATH}/${BETTY_DOC}" "${BIN_PATH}/${BETTY_DOC}"
ln -s "${APP_PATH}/${BETTY_WRAPPER}" "${BIN_PATH}/${BETTY_WRAPPER}"

echo ""
echo -e "Installing man pages.."

mkdir -p "${MAN_PATH}"
echo -e "MAN_PATH"
echo -e "$(pwd)"
echo -e "$MAN_PATH"

cp "man/betty.1" "${MAN_PATH}"
cp "man/${BETTY_STYLE}.1" "${MAN_PATH}"
cp "man/${BETTY_DOC}.1" "${MAN_PATH}"

echo ""
echo -e "All set."

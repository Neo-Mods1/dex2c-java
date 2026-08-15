#!/bin/sh
set -eu
if command -v gradle >/dev/null 2>&1; then
  exec gradle "$@"
fi
if [ -x "${GRADLE_HOME:-}/bin/gradle" ]; then
  exec "${GRADLE_HOME}/bin/gradle" "$@"
fi
echo "Gradle 8.x is required. Install Gradle or set GRADLE_HOME, then rerun: ./gradlew $*" >&2
exit 127

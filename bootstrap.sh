#!/bin/sh
set -eu
if command -v gradle >/dev/null 2>&1; then exec gradle "$@"; fi
if [ -n "${GRADLE_HOME:-}" ] && [ -x "$GRADLE_HOME/bin/gradle" ]; then exec "$GRADLE_HOME/bin/gradle" "$@"; fi
echo "Install Gradle 8.x and JDK 11+, then run ./gradlew clean build" >&2
exit 127

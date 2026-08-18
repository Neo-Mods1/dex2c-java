#!/usr/bin/env sh
# Lightweight repository launcher. CI installs Gradle explicitly; locally we
# delegate to an installed Gradle 8.x executable instead of pretending this is
# a complete Gradle Wrapper distribution.
set -eu
if command -v gradle >/dev/null 2>&1; then
  exec gradle "$@"
fi
if [ -n "${GRADLE_HOME:-}" ] && [ -x "$GRADLE_HOME/bin/gradle" ]; then
  exec "$GRADLE_HOME/bin/gradle" "$@"
fi
printf '%s\n' 'Gradle 8.x is required. Install Gradle or set GRADLE_HOME, then rerun: ./gradlew' >&2
exit 127

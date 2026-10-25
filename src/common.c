#include <common.h>

void die(const char *msg) {
  if (errno != 0) {
    perror(msg);
  } else {
    fprintf(stderr, "Error: %s\n", msg);
  }
  exit(EXIT_FAILURE);
}

void warn_msg(const char *prefix, const char *msg) {
  if (errno != 0) {
    fprintf(stderr, "%s: %s: %s\n", prefix, msg, strerror(errno));
  } else {
    fprintf(stderr, "%s: %s\n", prefix, msg);
  }
}

void *safe_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr && size > 0) {
    die("malloc failed");
  }
  return ptr;
}

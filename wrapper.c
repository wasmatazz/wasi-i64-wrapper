
#include <wasmatazz.h>
#include <stdint.h>

#define P64(name) int hi_##name, int lo_##name
#define V64(name) (int)(name >> 32), (int)name

wasm_import int fd_seek32(int fd, P64(offset), int whence, uint64_t* new_offset);
wasm_export_as("fd_seek") int fd_seek_wrapper(int fd, int64_t offset, int whence, uint64_t* new_offset) {
  return fd_seek32(fd, V64(offset), whence, new_offset);
}

wasm_import int fd_advise32(int fd, P64(offset), P64(len), int advice);
wasm_export_as("fd_advise") int fd_advise_wrapper(int fd, uint64_t offset, uint64_t len, int advice) {
  return fd_advise32(fd, V64(offset), V64(len), advice);
}

wasm_import int fd_allocate32(int fd, P64(offset), P64(len));
wasm_export_as("fd_allocate") int fd_allocate_wrapper(int fd, uint64_t offset, uint64_t len) {
  return fd_allocate32(fd, V64(offset), V64(len));
}

wasm_import int fd_filestat_set_size32(int fd, P64(len));
wasm_export_as("fd_filestat_set_size") int fd_filestat_set_size_wrapper(int fd, uint64_t len) {
  return fd_filestat_set_size32(fd, V64(len));
}

wasm_import int fd_filestat_set_times32(int fd, P64(atim), P64(mtim), int fstflags);
wasm_export_as("fd_filestat_set_times") int fd_filestat_set_times_wrapper(int fd, uint64_t atim, uint64_t mtim, int fstflags) {
  return fd_filestat_set_times32(fd, V64(atim), V64(mtim), fstflags);
}

wasm_import int fd_pread32(int fd, void* array, P64(offset), uint64_t* bytes_read);
wasm_export_as("fd_pread") int fd_pdread_wrapper(int fd, void* array, uint64_t offset, uint64_t* bytes_read) {
  return fd_pread32(fd, array, V64(offset), bytes_read);
}

wasm_import int fd_pwrite32(int fd, void* array, P64(offset), uint64_t* bytes_written);
wasm_export_as("fd_pwrite") int fd_pwrite_wrapper(int fd, void* array, uint64_t offset, uint64_t* bytes_written) {
  return fd_pwrite32(fd, array, V64(offset), bytes_written);
}

wasm_import int path_filestat_set_times32(int fd, int flags, void* path, P64(atim), P64(mtim), int fstflags);
wasm_export_as("path_filestat_set_times") int path_filestat_set_times_wrapper(int fd, int flags, void* path, uint64_t atim, uint64_t mtim, int fstflags) {
  return path_filestat_set_times32(fd, flags, path, V64(atim), V64(mtim), fstflags);
}

wasm_import int fd_fdstat_set_rights32(int fd, P64(base), P64(inherit));
wasm_export_as("fd_fdstat_set_rights") int fd_fdstat_set_rights_wrapper(int fd, uint64_t base, uint64_t inherit) {
  return fd_fdstat_set_rights32(fd, V64(base), V64(inherit));
}

wasm_import int path_open32(int fd, int dirflags, void* path, int oflags, P64(base), P64(inherit), int fdflags, void* out_fd);
wasm_export_as("path_open") int path_open_wrapper(int fd, int dirflags, void* path, int oflags, uint64_t base, uint64_t inherit, int fdflags, void* out_fd) {
  return path_open32(fd, dirflags, path, oflags, V64(base), V64(inherit), fdflags, out_fd);
}

wasm_import int fd_readdir32(int fd, void* buf, P64(size), P64(cookie), void* out_size);
wasm_export_as("fd_readdir") int fd_readdir_wrapper(int fd, void* buf, uint64_t size, uint64_t cookie, void* out_size) {
  return fd_readdir32(fd, buf, V64(size), V64(cookie), out_size);
}

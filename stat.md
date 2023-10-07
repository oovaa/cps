Certainly! Here's a cheat sheet in Markdown format that provides an overview of the `stat` structure and its associated functions:

## `stat` Structure and Functions Cheat Sheet

### `stat` Structure

The `stat` structure is used to store information about a file.

```c
struct stat {
    dev_t     st_dev;         // ID of device containing file
    ino_t     st_ino;         // Inode number
    mode_t    st_mode;        // File type and mode
    nlink_t   st_nlink;       // Number of hard links
    uid_t     st_uid;         // User ID of owner
    gid_t     st_gid;         // Group ID of owner
    dev_t     st_rdev;        // Device ID (if special file)
    off_t     st_size;        // Total size, in bytes
    blksize_t st_blksize;     // Block size for file system I/O
    blkcnt_t  st_blocks;      // Number of allocated blocks
    time_t    st_atime;       // Last access time
    time_t    st_mtime;       // Last modification time
    time_t    st_ctime;       // Last status change time
};
```

### `stat` Functions

1. **`int stat(const char *path, struct stat *buf)`**

   - Retrieves file information specified by `path` and stores it in the `stat` structure pointed to by `buf`.
   - Returns 0 on success, -1 on failure.

2. **`int fstat(int fd, struct stat *buf)`**

   - Retrieves file information for the file associated with the file descriptor `fd` and stores it in the `stat` structure pointed to by `buf`.
   - Returns 0 on success, -1 on failure.

3. **`int lstat(const char *path, struct stat *buf)`**

   - Retrieves file information specified by `path`, similar to `stat()`, but for symbolic links, it returns information about the link itself rather than the file it refers to.
   - Returns 0 on success, -1 on failure.

4. **`int chmod(const char *path, mode_t mode)`**

   - Changes the permissions of a file specified by `path` to the specified `mode`.
   - Returns 0 on success, -1 on failure.

5. **`int fchmod(int fd, mode_t mode)`**

   - Changes the permissions of the file associated with the file descriptor `fd` to the specified `mode`.
   - Returns 0 on success, -1 on failure.

6. **`int chown(const char *path, uid_t owner, gid_t group)`**

   - Changes the owner and group of a file specified by `path` to the specified `owner` and `group`.
   - Returns 0 on success, -1 on failure.

7. **`int fchown(int fd, uid_t owner, gid_t group)`**

   - Changes the owner and group of the file associated with the file descriptor `fd` to the specified `owner` and `group`.
   - Returns 0 on success, -1 on failure.

8. **`int utime(const char *path, const struct utimbuf *times)`**

   - Changes the access and modification times of a file specified by `path` to the values specified by `times`.
   - Returns 0 on success, -1 on failure.

9. **`int mkdir(const char *path, mode_t mode)`**

   - Creates a new directory with the specified `path` and permissions `mode`.
   - Returns 0 on success, -1 on failure.

10. **`int rmdir(const char *path)`**

    - Removes the directory specified by `path`.
    - Returns 0 on success, -1 on failure.

11. **`int unlink(const char *path)`**

    - Removes the file specified by `path`.
    - Returns 0 on success, -1 on failure.

12. **`int symlink(const char *target, const char *linkpath)`**

    - Creates a symbolic link at `linkpath` pointing to the file `target`.
    - Returns 0 on success, -1 on failure.

#code 

Certainly! Here's an updated version of the cheat sheet with code examples for each point:

## `stat` Structure and Functions Cheat Sheet

### `stat` Structure

The `stat` structure is used to store information about a file.

```c
struct stat {
    dev_t     st_dev;         // ID of device containing file
    ino_t     st_ino;         // Inode number
    mode_t    st_mode;        // File type and mode
    nlink_t   st_nlink;       // Number of hard links
    uid_t     st_uid;         // User ID of owner
    gid_t     st_gid;         // Group ID of owner
    dev_t     st_rdev;        // Device ID (if special file)
    off_t     st_size;        // Total size, in bytes
    blksize_t st_blksize;     // Block size for file system I/O
    blkcnt_t  st_blocks;      // Number of allocated blocks
    time_t    st_atime;       // Last access time
    time_t    st_mtime;       // Last modification time
    time_t    st_ctime;       // Last status change time
};
```

### `stat` Functions

1. **`int stat(const char *path, struct stat *buf)`**

   ````c
   #include <sys/stat.h>

   int main() {
       struct stat fileStat;
       if (stat("/path/to/file", &fileStat) == 0) {
           // File information retrieved successfully
           // Access the file information using fileStat struct
       } else {
           // Error occurred while retrieving file information
       }
       return 0;
   }
   ```

2. **`int fstat(int fd, struct stat *buf)`**

   ````c
   #include <sys/stat.h>
   #include <fcntl.h>

   int main() {
       int fileDescriptor = open("/path/to/file", O_RDONLY);
       struct stat fileStat;
       if (fstat(fileDescriptor, &fileStat) == 0) {
           // File information retrieved successfully
           // Access the file information using fileStat struct
       } else {
           // Error occurred while retrieving file information
       }
       close(fileDescriptor);
       return 0;
   }
   ```

3. **`int lstat(const char *path, struct stat *buf)`**

   ````c
   #include <sys/stat.h>

   int main() {
       struct stat fileStat;
       if (lstat("/path/to/symlink", &fileStat) == 0) {
           // Symbolic link information retrieved successfully
           // Access the link information using fileStat struct
       } else {
           // Error occurred while retrieving link information
       }
       return 0;
   }
   ```

4. **`int chmod(const char *path, mode_t mode)`**

   ````c
   #include <sys/stat.h>

   int main() {
       if (chmod("/path/to/file", S_IRWXU | S_IRGRP | S_IROTH) == 0) {
           // File permissions changed successfully
       } else {
           // Error occurred while changing file permissions
       }
       return 0;
   }
   ```

5. **`int fchmod(int fd, mode_t mode)`**

   ````c
   #include <sys/stat.h>
   #include <fcntl.h>

   int main() {
       int fileDescriptor = open("/path/to/file", O_WRONLY);
       if (fchmod(fileDescriptor, S_IRUSR | S_IWUSR) == 0) {
           // File permissions changed successfully
       } else {
           // Error occurred while changing file permissions
       }
       close(fileDescriptor);
       return 0;
   }
   ```

6. **`int chown(const char *path, uid_t owner, gid_t group)`**

   ````c
   #include <sys/stat.h>

   int main() {
       if (chown("/path/to/file", 1000, 1000) == 0) {
           // Owner and group changed successfully
       } else {
           // Error occurred while changing owner and group
       }
       return 0;
   }
   ```

7. **`int fchown(int fd, uid_t owner, gid_t group)`**

   ````c
   #include <sys/stat.h>
   #include <fcntl.h>

   int main() {
       int fileDescriptor = open("/path/to/file", O_WRONLY);
       if (fchown(fileDescriptor, 1000, 1000) == 0) {
           // Owner and group changed successfully
       } else {
           // Error occurred while changing owner and group
       }
       close(fileDescriptor);
       return 0;
   }
   ```

8. **`int utime(const char *path, const struct utMy apologies for the abrupt interruption. Here's the continuation of the code examples:

8. **`int utime(const char *path, const struct utimbuf *times)`**

   ````c
   #include <utime.h>

   int main() {
       struct utimbuf fileTimes;
       fileTimes.actime = 1633550400;  // Set the access time
       fileTimes.modtime = 1633550400; // Set the modification time

       if (utime("/path/to/file", &fileTimes) == 0) {
           // Access and modification times changed successfully
       } else {
           // Error occurred while changing access and modification times
       }
       return 0;
   }
   ```

9. **`int mkdir(const char *path, mode_t mode)`**

   ````c
   #include <sys/stat.h>

   int main() {
       if (mkdir("/path/to/directory", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == 0) {
           // Directory created successfully
       } else {
           // Error occurred while creating directory
       }
       return 0;
   }
   ```

10. **`int rmdir(const char *path)`**

    ```c
    #include <unistd.h>

    int main() {
        if (rmdir("/path/to/directory") == 0) {
            // Directory removed successfully
        } else {
            // Error occurred while removing directory
        }
        return 0;
    }
    ```

11. **`int unlink(const char *path)`**

    ```c
    #include <unistd.h>

    int main() {
        if (unlink("/path/to/file") == 0) {
            // File removed successfully
        } else {
            // Error occurred while removing file
        }
        return 0;
    }
    ```

12. **`int symlink(const char *target, const char *linkpath)`**

    ```c
    #include <unistd.h>

    int main() {
        if (symlink("/path/to/target", "/path/to/symlink") == 0) {
            // Symbolic link created successfully
        } else {
            // Error occurred while creating symbolic link
        }
        return 0;
    }
    ```

require 'rake/clean'
require 'rake/loaders/makefile'
require 'pathname'

# ==============================================================================
#                                    VARIABLES
# ==============================================================================

# Source directories
SRC_DIR    = './src'
SERVER_DIR = "#{SRC_DIR}/server"
CLIENT_DIR = "#{SRC_DIR}/client"
SUB_DIRS   = Pathname.new(SRC_DIR).children.select { |c| c.directory? }
# Build directories
BUILD_DIR  = './build'
OBJ_DIR    = "#{BUILD_DIR}/objs"
DEP_DIR    = "#{BUILD_DIR}/deps"
BIN_DIR    = './bin'

# Where to find headers
HEADERS    = [
  './include',
  './vendor/libft'
]
HFLAGS     = HEADERS.collect { |dir| "-I#{dir}" }.join(' ')
# Where to find libraries
LIBRARIES  = {
  './vendor/libft/': 'ft'
}
LIBFLAGS   = LIBRARIES.collect { |key, value| "-L#{key} -l#{value}" }.join(' ')

# Compilation flags
CC         = 'clang'
CFLAGS     = "-Wall -Wextra -Werror #{HFLAGS}"
DFLAGS     = "#{HFLAGS} -M -MP -MM"

DEBUG_FLAGS = '-g -fsanitize=address'

# ==============================================================================
#                                     FILES
# ==============================================================================

# Source files
SRC_FILES    = Rake::FileList.new("#{SRC_DIR}/**/*.c") do |file|
  file.exclude { |f| "git ls-files #{f}".empty? }
end

OBJ_FILES    = SRC_FILES.pathmap("#{OBJ_DIR}/%n.o")
DEP_FILES    = SRC_FILES.pathmap("#{DEP_DIR}/%n.mf")

# Files used to compile client
CLIENT_FILES = SRC_FILES.clone
                        .exclude("#{SERVER_DIR}/**/*.c")
                        .pathmap("#{OBJ_DIR}/%n.o")
# Files used to compile server
SERVER_FILES = SRC_FILES.clone
                        .exclude("#{CLIENT_DIR}/**/*.c")
                        .pathmap("#{OBJ_DIR}/%n.o")


# ==============================================================================
#                                  DEBUG FILES
# ==============================================================================

OBJ_FILES_DEBUG = SRC_FILES.pathmap("#{OBJ_DIR}/debug/%n.o")
DEP_FILES_DEBUG = SRC_FILES.pathmap("#{DEP_DIR}/debug/%n.mf")

# Files used to compile client
CLIENT_FILES_DEBUG = SRC_FILES.clone
                        .exclude("#{SERVER_DIR}/**/*.c")
                        .pathmap("#{OBJ_DIR}/debug/%n.o")
# Files used to compile server
SERVER_FILES_DEBUG = SRC_FILES.clone
                        .exclude("#{CLIENT_DIR}/**/*.c")
                        .pathmap("#{OBJ_DIR}/debug/%n.o")

# Files to remove with clean and clobber
CLEAN.include(OBJ_FILES, OBJ_FILES_DEBUG)
CLOBBER.include("#{BIN_DIR}/*", "#{BIN_DIR}/debug/*")

# ==============================================================================
#                                   DIRECTORIES
# ==============================================================================

# Default directories
directory OBJ_DIR
directory DEP_DIR

# ==============================================================================
#                                      RULES
# ==============================================================================

# By default, builds binaries
task default: :build

# Builds client and server
task build: [:client, :server]

# Builds the client if all object files have been compiled
file client: OBJ_FILES do
  sh "#{CC} #{CFLAGS} #{CLIENT_FILES} -o #{BIN_DIR}/client #{LIBFLAGS}"
end

# Builds the server if all object files have been compiled
file server: OBJ_FILES do
  sh "#{CC} #{CFLAGS} #{SERVER_FILES} -o #{BIN_DIR}/server #{LIBFLAGS}"
end

# ==============================================================================
#                                  DEBUG RULES
# ==============================================================================

# Compiles with debug options
task :debug do
  # Adds debug options to C flags
  CFLAGS << ' ' << DEBUG_FLAGS

  # Updates compilation directories
  BIN_DIR << '/debug'
  OBJ_DIR << '/debug'
  DEP_DIR << '/debug'

  # Calls build task
  Rake::Task[:build_debug].invoke
end

task build_debug: [:client_debug, :server_debug]

# Builds the client if all object files have been compiled
file client_debug: OBJ_FILES_DEBUG do
  sh "#{CC} #{CFLAGS} #{CLIENT_FILES_DEBUG} -o #{BIN_DIR}/client #{LIBFLAGS}"
end

# Builds the server if all object files have been compiled
file server_debug: OBJ_FILES_DEBUG do
  sh "#{CC} #{CFLAGS} #{SERVER_FILES_DEBUG} -o #{BIN_DIR}/server #{LIBFLAGS}"
end

# ==============================================================================
#                               DEPENDENCY RULES
# ==============================================================================

# Builds an objet file if the corresponding C files exists
rule '.o' => [->(f) { source_objs(f) }, OBJ_DIR] do |task|
  sh "#{CC} #{CFLAGS} -c #{task.source} -o #{task.name}"
end

# Builds a dependency file if the corresponding C files exists
rule ".mf" => [->(f) { source_deps(f) }, DEP_DIR] do |task|
  cmd = "#{CC} #{DFLAGS} #{task.source} -MT #{task.source.ext('.o')}"
  make_target = `#{cmd}`

  open(task.name.to_s, 'w') do |file|
    file.puts make_target.to_s
    file.puts make_target.sub('.o:', '.mf:').to_s
  end
end

# Displays debug information
task :info do
  puts '-------------------' 
  puts '>> SUBDIRECTORIES'
  puts SUB_DIRS
  puts '-------------------' 
  puts '>> SOURCE FILES'
  puts SRC_FILES
  puts '-------------------' 
  puts '>> CLIENT FILES'
  puts CLIENT_FILES
  puts '-------------------' 
  puts '>> SERVER FILES'
  puts SERVER_FILES
  puts '-------------------' 
  puts '>> OBJECT FILES'
  puts OBJ_FILES
  puts '-------------------' 
  puts '>> DEPENDENCY FILES'
  puts DEP_FILES
  puts '-------------------' 
end

# ==============================================================================
#                                 HELPER FUNCTIONS
# ==============================================================================

# Determines the location of the c file associated to an object file.
def source_objs(o_file)
  SRC_FILES.detect do |c_file|
    SUB_DIRS.detect do |dir|
      c_file.pathmap('%X') == o_file.pathmap("#{dir}/%n")
    end
  end
end

# Determines the location of the c file associated to a dependency file.
def source_deps(d_file)
  SRC_FILES.detect do |c_file|
    SUB_DIRS.detect do |dir|
      c_file.pathmap('%X') == d_file.pathmap("#{dir}/%n")
    end
  end
end

# ==============================================================================
#                               DEPENDENCY INCLUSION
# ==============================================================================

# Imports each dependency file, creating it if it does not exist.
DEP_FILES.each do |d_file|
  file d_file
  puts "importing #{d_file}"
  import d_file
end

DEP_FILES_DEBUG.each do |d_file|
  file d_file
  puts "importing #{d_file}"
  import d_file
end

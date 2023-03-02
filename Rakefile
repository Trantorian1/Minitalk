require 'rake/clean'
require 'rake/loaders/makefile'
require 'pathname'

SRC_DIR    = './src'
SERVER_DIR = "#{SRC_DIR}/server"
CLIENT_DIR = "#{SRC_DIR}/client"
SUB_DIRS   = Pathname.new(SRC_DIR).children.select { |c| c.directory? }
BUILD_DIR  = './build'
OBJ_DIR    = "#{BUILD_DIR}/objs"
DEP_DIR    = "#{BUILD_DIR}/deps"
BIN_DIR    = './bin'

HEADERS    = [
  './include',
  './vendor/libft'
]
HFLAGS     = HEADERS.collect { |dir| "-I#{dir}" }.join(' ')

LIBRARIES  = {
  './vendor/libft/': 'ft'
}
LIBFLAGS   = LIBRARIES.collect { |key, value| "-L#{key} -l#{value}" }.join(' ')

CC         = 'clang'
CFLAGS     = "-Wall -Wextra -Werror #{HFLAGS}"
DFLAGS     = "#{HFLAGS} -M -MP -MM"

SRC_FILES    = Rake::FileList.new("#{SRC_DIR}/**/*.c") do |file|
  file.exclude { |f| "git ls-files #{f}".empty? }
end

OBJ_FILES    = SRC_FILES.pathmap("#{OBJ_DIR}/%n.o")
DEP_FILES    = SRC_FILES.pathmap("#{DEP_DIR}/%n.mf")

CLIENT_FILES = SRC_FILES.clone
                        .exclude("#{SERVER_DIR}/**/*.c")
                        .pathmap("#{OBJ_DIR}/%n.o")
SERVER_FILES = SRC_FILES.clone
                        .exclude("#{CLIENT_DIR}/**/*.c")
                        .pathmap("#{OBJ_DIR}/%n.o")

CLEAN.include(OBJ_FILES)
CLOBBER.include("#{BIN_DIR}/*")

directory OBJ_DIR
directory DEP_DIR

task default: [:client, :server]

file client: OBJ_FILES do
  sh "#{CC} #{CFLAGS} #{CLIENT_FILES} -o #{BIN_DIR}/client #{LIBFLAGS}"
end

file server: OBJ_FILES do
  sh "#{CC} #{CFLAGS} #{SERVER_FILES} -o #{BIN_DIR}/server #{LIBFLAGS}"
end

rule '.o' => [->(f) { source_objs(f) }, OBJ_DIR] do |task|
  sh "#{CC} #{CFLAGS} -c #{task.source} -o #{task.name}"
end

rule ".mf" => [->(f) { source_deps(f) }, DEP_DIR] do |task|
  cmd = "#{CC} #{DFLAGS} #{task.source} -MT #{task.source.ext('.o')}"
  make_target = `#{cmd}`

  open(task.name.to_s, 'w') do |file|
    file.puts make_target.to_s
    file.puts make_target.sub('.o:', '.mf:').to_s
  end
end

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

task :debug do
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

# Imports each dependency file, creating it if it does not exist.
DEP_FILES.each do |d_file|
  file d_file
  puts "importing #{d_file}"
  import d_file
end

require 'rake/clean'
require 'rake/loaders/makefile'

RAKE_MAP = {
  './src/client/': 'client',
  './src/server/': 'server'
}.freeze
BINDIR = 'bin/'.freeze

directory BINDIR

task default: :binary

file binary: [*RAKE_MAP.keys, BINDIR] do
  RAKE_MAP.each do |dir, binary| 
    sh "rake -C #{dir} && mv #{dir}#{binary} #{BINDIR}#{binary}" 
  end
end

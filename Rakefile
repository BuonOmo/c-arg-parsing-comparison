require "rake/extensiontask"

Rake::ExtensionTask.new "geo" do |ext|
  ext.lib_dir = "lib/geo"
end


task default: :compile do
  require "benchmark/ips"
  require_relative "lib/geo"

  Benchmark.ips do |x|
    x.report("parse in C ext") { Geo.c_voronoi_diagram(:env, :p1, :p2, tolerance: 1) }
    x.report("parse in Ruby") { Geo.ruby_voronoi_diagram(:env, :p1, :p2, tolerance: 1) }
    x.compare!
  end
end

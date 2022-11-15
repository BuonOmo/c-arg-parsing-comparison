require_relative "geo/geo" # The C extension

module Geo
  def self.ruby_voronoi_diagram(envelope, *polygons, tolerance:, only_edges: false)
    Hidden.voronoi_diagram(envelope, polygons, tolerance, only_edges)
  end
end

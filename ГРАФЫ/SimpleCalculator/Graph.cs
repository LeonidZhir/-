using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace GraphVisualization
{
    public class Vertex
    {
        public Point Position { get; set; }
    }

    public class Edge
    {
        public int Destination { get; set; }
        public int Weight { get; set; }
    }

    public class Graph
    {
        public List<Vertex> Vertices { get; private set; }
        public List<List<Edge>> AdjacencyList { get; private set; }

        public Graph()
        {
            Vertices = new List<Vertex>();
            AdjacencyList = new List<List<Edge>>();
        }

        public void AddVertex(Point position)
        {
            Vertices.Add(new Vertex { Position = position });
            AdjacencyList.Add(new List<Edge>());
        }

        public void RemoveVertex(int v)
        {
            if (v < 0 || v >= Vertices.Count) return;

            Vertices.RemoveAt(v);
            AdjacencyList.RemoveAt(v);

            for (int i = 0; i < AdjacencyList.Count; i++)
            {
                AdjacencyList[i] = AdjacencyList[i]
                    .Where(edge => edge.Destination != v)
                    .Select(edge => new Edge
                    {
                        Destination = edge.Destination > v ? edge.Destination - 1 : edge.Destination,
                        Weight = edge.Weight
                    })
                    .ToList();
            }
        }

        public void AddEdge(int src, int dest, int weight)
        {
            if (src < 0 || src >= Vertices.Count || dest < 0 || dest >= Vertices.Count) return;

            bool updated = false;
            foreach (var edge in AdjacencyList[src])
            {
                if (edge.Destination == dest)
                {
                    edge.Weight = weight;
                    updated = true;
                    break;
                }
            }
            foreach (var edge in AdjacencyList[dest])
            {
                if (edge.Destination == src)
                {
                    edge.Weight = weight;
                    updated = true;
                    break;
                }
            }

            if (!updated)
            {
                AdjacencyList[src].Add(new Edge { Destination = dest, Weight = weight });
                AdjacencyList[dest].Add(new Edge { Destination = src, Weight = weight });
            }
        }

        public void RemoveEdge(int src, int dest)
        {
            if (src < 0 || src >= Vertices.Count || dest < 0 || dest >= Vertices.Count) return;

            AdjacencyList[src] = AdjacencyList[src].Where(edge => edge.Destination != dest).ToList();
            AdjacencyList[dest] = AdjacencyList[dest].Where(edge => edge.Destination != src).ToList();
        }

        public void EditEdgeWeight(int src, int dest, int newWeight)
        {
            if (src < 0 || src >= Vertices.Count || dest < 0 || dest >= Vertices.Count) return;

            foreach (var edge in AdjacencyList[src])
                if (edge.Destination == dest)
                    edge.Weight = newWeight;

            foreach (var edge in AdjacencyList[dest])
                if (edge.Destination == src)
                    edge.Weight = newWeight;
        }

        public List<int> Dijkstra(int start)
        {
            int V = Vertices.Count;
            var dist = Enumerable.Repeat(int.MaxValue, V).ToList();
            dist[start] = 0;

            var pq = new SortedSet<(int dist, int vertex)>();
            pq.Add((0, start));

            while (pq.Count > 0)
            {
                var (d, u) = pq.Min;
                pq.Remove((d, u));

                if (d > dist[u]) continue;

                foreach (var edge in AdjacencyList[u])
                {
                    int v = edge.Destination;
                    int w = edge.Weight;
                    if (dist[u] != int.MaxValue && dist[u] + w < dist[v])
                    {
                        pq.Remove((dist[v], v));
                        dist[v] = dist[u] + w;
                        pq.Add((dist[v], v));
                    }
                }
            }

            return dist;
        }
    }
}
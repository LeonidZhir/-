using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace GraphVisualization
{
    public partial class GraphForm : Form
    {
        private Graph graph;
        private List<int> distances;
        private int startVertex = 0;

        public GraphForm()
        {
            InitializeComponent();
            graph = new Graph();
            distances = new List<int>();
            InitializeGraph();
        }

        private void InitializeGraph()
        {
            // Добавление вершин и рёбер по умолчанию
            graph.AddVertex(new Point(400, 100));
            graph.AddVertex(new Point(300, 200));
            graph.AddVertex(new Point(200, 300));
            graph.AddVertex(new Point(500, 300));
            graph.AddVertex(new Point(350, 350));
            graph.AddVertex(new Point(600, 200));

            graph.AddEdge(0, 1, 11);
            graph.AddEdge(1, 2, 18);
            graph.AddEdge(2, 4, 6);
            graph.AddEdge(4, 1, 23);
            graph.AddEdge(4, 5, 3);
            graph.AddEdge(5, 0, 16);
            graph.AddEdge(5, 3, 9);
            graph.AddEdge(3, 2, 16);

            CalculateDistances();
        }

        private void CalculateDistances()
        {
            distances = graph.Dijkstra(startVertex);
            pictureBox.Invalidate();
        }

        private void pictureBox_Paint(object sender, PaintEventArgs e)
        {
            DrawGraph(e.Graphics);
        }

        private void DrawGraph(Graphics g)
        {
            const int radius = 25;
            Font font = new Font("Arial", 12);

            // Рисуем рёбра
            for (int u = 0; u < graph.Vertices.Count; u++)
            {
                Point posU = graph.Vertices[u].Position;
                foreach (var edge in graph.AdjacencyList[u])
                {
                    Point posV = graph.Vertices[edge.Destination].Position;
                    g.DrawLine(Pens.Black, posU, posV);

                    // Вес ребра
                    Point mid = new Point((posU.X + posV.X) / 2, (posU.Y + posV.Y) / 2);
                    g.DrawString(edge.Weight.ToString(), font, Brushes.Blue, mid);
                }
            }

            // Рисуем вершины
            for (int i = 0; i < graph.Vertices.Count; i++)
            {
                Point pos = graph.Vertices[i].Position;
                Color fillColor = distances[i] != int.MaxValue ? Color.LightGreen : Color.LightPink;
                if (i == startVertex)
                    fillColor = Color.Yellow;

                g.FillEllipse(new SolidBrush(fillColor), pos.X - radius, pos.Y - radius, radius * 2, radius * 2);
                g.DrawEllipse(Pens.Black, pos.X - radius, pos.Y - radius, radius * 2, radius * 2);

                // Номер вершины
                g.DrawString((i + 1).ToString(), font, Brushes.Black, pos.X - radius / 2, pos.Y - radius / 2);

                // Расстояние
                if (distances[i] != int.MaxValue)
                    g.DrawString("d=" + distances[i], font, Brushes.Black, pos.X - radius, pos.Y + radius);
            }
        }

        private void btnAddVertex_Click(object sender, EventArgs e)
        {
            var x = int.Parse(txtX.Text);
            var y = int.Parse(txtY.Text);
            graph.AddVertex(new Point(x, y));
            CalculateDistances();
        }

        private void btnRemoveVertex_Click(object sender, EventArgs e)
        {
            var v = int.Parse(txtVertex.Text) - 1;
            if (v >= 0 && v < graph.Vertices.Count)
            {
                graph.RemoveVertex(v);
                CalculateDistances();
            }
            else
                MessageBox.Show("Неверный номер вершины");
        }

        private void btnAddEdge_Click(object sender, EventArgs e)
        {
            var src = int.Parse(txtSrc.Text) - 1;
            var dest = int.Parse(txtDest.Text) - 1;
            var weight = int.Parse(txtWeight.Text);
            graph.AddEdge(src, dest, weight);
            CalculateDistances();
        }

        private void btnRemoveEdge_Click(object sender, EventArgs e)
        {
            var src = int.Parse(txtSrc.Text) - 1;
            var dest = int.Parse(txtDest.Text) - 1;
            graph.RemoveEdge(src, dest);
            CalculateDistances();
        }

        private void btnEditWeight_Click(object sender, EventArgs e)
        {
            var src = int.Parse(txtSrc.Text) - 1;
            var dest = int.Parse(txtDest.Text) - 1;
            var weight = int.Parse(txtWeight.Text);
            graph.EditEdgeWeight(src, dest, weight);
            CalculateDistances();
        }

        private void btnDijkstra_Click(object sender, EventArgs e)
        {
            startVertex = int.Parse(txtStartVertex.Text) - 1;
            if (startVertex >= 0 && startVertex < graph.Vertices.Count)
                CalculateDistances();
            else
                MessageBox.Show("Неверный номер вершины");
        }
    }
}
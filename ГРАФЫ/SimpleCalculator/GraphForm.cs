using System;
using System.Drawing;
using System.Windows.Forms;

namespace GraphVisualization
{
    public partial class GraphForm : Form
    {
        private Graph graph;

        public GraphForm()
        {
            InitializeComponent();
            graph = new Graph();
            graph.InitializeGraph(); // ������������� ����� � ������� ������
        }

        private void pictureBox_Paint(object sender, PaintEventArgs e)
        {
            var g = e.Graphics;
            g.Clear(Color.White);

            // ������ �����
            for (int i = 0; i < graph.Vertices.Count; i++)
            {
                foreach (var edge in graph.AdjacencyList[i])
                {
                    if (i < edge.Destination) // ����� �� �������� ����� ������
                    {
                        var p1 = graph.Vertices[i].Position;
                        var p2 = graph.Vertices[edge.Destination].Position;
                        g.DrawLine(Pens.Black, p1, p2);

                        // ������ ��� ����� � ��������
                        var midX = (p1.X + p2.X) / 2;
                        var midY = (p1.Y + p2.Y) / 2;
                        g.DrawString(edge.Weight.ToString(), Font, Brushes.Red, midX, midY);
                    }
                }
            }

            // ������ �������
            for (int i = 0; i < graph.Vertices.Count; i++)
            {
                var p = graph.Vertices[i].Position;
                var rect = new Rectangle(p.X - 15, p.Y - 15, 30, 30);
                g.FillEllipse(Brushes.LightBlue, rect);
                g.DrawEllipse(Pens.Black, rect);
                g.DrawString(i.ToString(), Font, Brushes.Black, p.X - 7, p.Y - 10);
            }
        }

        private void btnAddVertex_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtX.Text, out int x) && int.TryParse(txtY.Text, out int y))
            {
                graph.AddVertex(new Point(x, y));
                pictureBox.Invalidate();
            }
            else
            {
                MessageBox.Show("������� ���������� ���������� X � Y.");
            }
        }

        private void btnRemoveVertex_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtVertex.Text, out int vertex))
            {
                graph.RemoveVertex(vertex);
                pictureBox.Invalidate();
            }
            else
            {
                MessageBox.Show("������� ���������� ����� �������.");
            }
        }

        private void btnAddEdge_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtSrc.Text, out int src) &&
                int.TryParse(txtDest.Text, out int dest) &&
                int.TryParse(txtWeight.Text, out int weight))
            {
                graph.AddEdge(src, dest, weight);
                pictureBox.Invalidate();
            }
            else
            {
                MessageBox.Show("������� ���������� �������� ��� �����.");
            }
        }

        private void btnRemoveEdge_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtSrc.Text, out int src) &&
                int.TryParse(txtDest.Text, out int dest))
            {
                graph.RemoveEdge(src, dest);
                pictureBox.Invalidate();
            }
            else
            {
                MessageBox.Show("������� ���������� �������� ��� �����.");
            }
        }

        private void btnEditWeight_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtSrc.Text, out int src) &&
                int.TryParse(txtDest.Text, out int dest) &&
                int.TryParse(txtWeight.Text, out int newWeight))
            {
                graph.EditEdgeWeight(src, dest, newWeight);
                pictureBox.Invalidate();
            }
            else
            {
                MessageBox.Show("������� ���������� �������� ��� ��������� ����.");
            }
        }

        private void btnDijkstra_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtStartVertex.Text, out int startVertex))
            {
                if (startVertex < 0 || startVertex >= graph.Vertices.Count)
                {
                    MessageBox.Show("��������� ������� ��� ���������.");
                    return;
                }

                var distances = graph.Dijkstra(startVertex);
                string result = $"���������� �� ������� {startVertex}:\n";
                for (int i = 0; i < distances.Count; i++)
                {
                    result += $"�� ������� {i}: {(distances[i] == int.MaxValue ? "INF" : distances[i].ToString())}\n";
                }
                MessageBox.Show(result, "���������� ��������� ��������");
            }
            else
            {
                MessageBox.Show("������� ���������� ����� ��������� �������.");
            }
        }

        private void btnFloydWarshall_Click(object sender, EventArgs e)
        {
            int[,] distances = graph.FloydWarshall();
            int V = graph.Vertices.Count;

            string result = "������� ���������� ����� ����� ������ ������:\n\n";

            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (distances[i, j] == int.MaxValue)
                        result += "INF".PadLeft(5);
                    else
                        result += distances[i, j].ToString().PadLeft(5);
                }
                result += "\n";
            }

            MessageBox.Show(result, "���������� ��������� ������-��������");
        }
    }
}
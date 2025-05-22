using System;
using System.Drawing;
using System.Windows.Forms;

namespace BinarySearchTreeApp
{
    public partial class MainForm : Form
    {
        private BinarySearchTree bst;

        public MainForm()
        {
            InitializeComponent();
            bst = new BinarySearchTree();

            // ��� ������� ������� ��������� �����
            foreach (char c in "FBADCEGIH")
                bst.Insert(c);

            UpdateTreeVisualization();
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtInput.Text))
            {
                char key = txtInput.Text[0];
                bst.Insert(key);
                txtInput.Clear();
                UpdateTreeVisualization();
            }
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtInput.Text))
            {
                char key = txtInput.Text[0];
                bst.Remove(key);
                txtInput.Clear();
                UpdateTreeVisualization();
            }
        }

        private void btnPreOrder_Click(object sender, EventArgs e)
        {
            var list = bst.PreOrder();
            txtOutput.Text = "������ �����: " + string.Join(" ", list);
        }

        private void btnInOrder_Click(object sender, EventArgs e)
        {
            var list = bst.InOrder();
            txtOutput.Text = "������������ �����: " + string.Join(" ", list);
        }

        private void btnPostOrder_Click(object sender, EventArgs e)
        {
            var list = bst.PostOrder();
            txtOutput.Text = "�������� �����: " + string.Join(" ", list);
        }

        private void btnCount_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtInput.Text))
            {
                char key = txtInput.Text[0];
                int count = bst.CountOccurrences(key);
                txtOutput.Text = $"���������� '{key}': {count}";
            }
        }

        private void btnPrintHorizontal_Click(object sender, EventArgs e)
        {
            txtOutput.Clear();
            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);
                bst.PrintHorizontal();
                txtOutput.Text = sw.ToString();
            }
        }

        private void btnPrintVertical_Click(object sender, EventArgs e)
        {
            txtOutput.Clear();
            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);
                bst.PrintVertical();
                txtOutput.Text = sw.ToString();
            }
        }

        private void UpdateTreeVisualization()
        {
            this.Invalidate();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            bst.Draw(e.Graphics, this.ClientSize.Width / 2, 50, 200, 100);
        }
    }
}

namespace TSPVisualization
{
    partial class MainForm
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            pictureBox = new PictureBox();
            btnSolve = new Button();
            btnAddVertex = new Button();
            btnRemoveVertex = new Button();
            txtStartVertex = new TextBox();
            label7 = new Label();
            txtOptimalDistance = new TextBox();
            label8 = new Label();
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // pictureBox
            // 
            pictureBox.BackColor = Color.White;
            pictureBox.Location = new Point(13, 18);
            pictureBox.Margin = new Padding(4, 5, 4, 5);
            pictureBox.Name = "pictureBox";
            pictureBox.Size = new Size(1073, 671);
            pictureBox.TabIndex = 0;
            pictureBox.TabStop = false;
            pictureBox.Paint += pictureBox_Paint;
            // 
            // btnSolve
            // 
            btnSolve.Location = new Point(49, 714);
            btnSolve.Margin = new Padding(4, 5, 4, 5);
            btnSolve.Name = "btnSolve";
            btnSolve.Size = new Size(133, 35);
            btnSolve.TabIndex = 1;
            btnSolve.Text = "Решить";
            btnSolve.UseVisualStyleBackColor = true;
            // 
            // btnAddVertex
            // 
            btnAddVertex.Location = new Point(243, 714);
            btnAddVertex.Margin = new Padding(4, 5, 4, 5);
            btnAddVertex.Name = "btnAddVertex";
            btnAddVertex.Size = new Size(133, 35);
            btnAddVertex.TabIndex = 2;
            btnAddVertex.Text = "Добавить вершину";
            btnAddVertex.UseVisualStyleBackColor = true;
            // 
            // btnRemoveVertex
            // 
            btnRemoveVertex.Location = new Point(426, 714);
            btnRemoveVertex.Margin = new Padding(4, 5, 4, 5);
            btnRemoveVertex.Name = "btnRemoveVertex";
            btnRemoveVertex.Size = new Size(133, 35);
            btnRemoveVertex.TabIndex = 3;
            btnRemoveVertex.Text = "Удалить вершину";
            btnRemoveVertex.UseVisualStyleBackColor = true;
            // 
            // txtStartVertex
            // 
            txtStartVertex.Location = new Point(953, 722);
            txtStartVertex.Margin = new Padding(4, 5, 4, 5);
            txtStartVertex.Name = "txtStartVertex";
            txtStartVertex.Size = new Size(65, 27);
            txtStartVertex.TabIndex = 13;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(782, 722);
            label7.Margin = new Padding(4, 0, 4, 0);
            label7.Name = "label7";
            label7.Size = new Size(147, 20);
            label7.TabIndex = 20;
            label7.Text = "Стартовая вершина";
            // 
            // txtOptimalDistance
            // 
            txtOptimalDistance.Location = new Point(897, 691);
            txtOptimalDistance.Margin = new Padding(4, 5, 4, 5);
            txtOptimalDistance.Name = "txtOptimalDistance";
            txtOptimalDistance.ReadOnly = true;
            txtOptimalDistance.Size = new Size(200, 27);
            txtOptimalDistance.TabIndex = 21;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(748, 694);
            label8.Margin = new Padding(4, 0, 4, 0);
            label8.Name = "label8";
            label8.Size = new Size(141, 20);
            label8.TabIndex = 22;
            label8.Text = "Общая длина пути:";
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1110, 763);
            Controls.Add(label8);
            Controls.Add(txtOptimalDistance);
            Controls.Add(label7);
            Controls.Add(txtStartVertex);
            Controls.Add(btnRemoveVertex);
            Controls.Add(btnAddVertex);
            Controls.Add(btnSolve);
            Controls.Add(pictureBox);
            Margin = new Padding(4, 5, 4, 5);
            Name = "MainForm";
            Text = "Graph Visualization";
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Button btnSolve;
        private System.Windows.Forms.Button btnAddVertex;
        private System.Windows.Forms.Button btnRemoveVertex;
        private System.Windows.Forms.TextBox txtStartVertex;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtOptimalDistance; // Новое текстовое поле
        private System.Windows.Forms.Label label8; // Новая метка для текста расстояния
    }
}
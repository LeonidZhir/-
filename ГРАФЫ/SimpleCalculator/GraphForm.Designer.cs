namespace GraphVisualization
{
    partial class GraphForm
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
            btnAddVertex = new Button();
            btnRemoveVertex = new Button();
            btnAddEdge = new Button();
            btnRemoveEdge = new Button();
            btnEditWeight = new Button();
            btnDijkstra = new Button();
            txtX = new TextBox();
            txtY = new TextBox();
            txtVertex = new TextBox();
            txtSrc = new TextBox();
            txtDest = new TextBox();
            txtWeight = new TextBox();
            txtStartVertex = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            label7 = new Label();
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // pictureBox
            // 
            pictureBox.BackColor = Color.White;
            pictureBox.Location = new Point(16, 18);
            pictureBox.Margin = new Padding(4, 5, 4, 5);
            pictureBox.Name = "pictureBox";
            pictureBox.Size = new Size(1067, 615);
            pictureBox.TabIndex = 0;
            pictureBox.TabStop = false;
            pictureBox.Paint += pictureBox_Paint;
            // 
            // btnAddVertex
            // 
            btnAddVertex.Location = new Point(16, 643);
            btnAddVertex.Margin = new Padding(4, 5, 4, 5);
            btnAddVertex.Name = "btnAddVertex";
            btnAddVertex.Size = new Size(133, 35);
            btnAddVertex.TabIndex = 1;
            btnAddVertex.Text = "Добавить вершину";
            btnAddVertex.UseVisualStyleBackColor = true;
            btnAddVertex.Click += btnAddVertex_Click;
            // 
            // btnRemoveVertex
            // 
            btnRemoveVertex.Location = new Point(157, 643);
            btnRemoveVertex.Margin = new Padding(4, 5, 4, 5);
            btnRemoveVertex.Name = "btnRemoveVertex";
            btnRemoveVertex.Size = new Size(133, 35);
            btnRemoveVertex.TabIndex = 2;
            btnRemoveVertex.Text = "Удалить вершину";
            btnRemoveVertex.UseVisualStyleBackColor = true;
            btnRemoveVertex.Click += btnRemoveVertex_Click;
            // 
            // btnAddEdge
            // 
            btnAddEdge.Location = new Point(299, 643);
            btnAddEdge.Margin = new Padding(4, 5, 4, 5);
            btnAddEdge.Name = "btnAddEdge";
            btnAddEdge.Size = new Size(133, 35);
            btnAddEdge.TabIndex = 3;
            btnAddEdge.Text = "Добавить ребро";
            btnAddEdge.UseVisualStyleBackColor = true;
            btnAddEdge.Click += btnAddEdge_Click;
            // 
            // btnRemoveEdge
            // 
            btnRemoveEdge.Location = new Point(440, 643);
            btnRemoveEdge.Margin = new Padding(4, 5, 4, 5);
            btnRemoveEdge.Name = "btnRemoveEdge";
            btnRemoveEdge.Size = new Size(133, 35);
            btnRemoveEdge.TabIndex = 4;
            btnRemoveEdge.Text = "Удалить ребро";
            btnRemoveEdge.UseVisualStyleBackColor = true;
            btnRemoveEdge.Click += btnRemoveEdge_Click;
            // 
            // btnEditWeight
            // 
            btnEditWeight.Location = new Point(581, 643);
            btnEditWeight.Margin = new Padding(4, 5, 4, 5);
            btnEditWeight.Name = "btnEditWeight";
            btnEditWeight.Size = new Size(133, 35);
            btnEditWeight.TabIndex = 5;
            btnEditWeight.Text = "Изменить вес";
            btnEditWeight.UseVisualStyleBackColor = true;
            btnEditWeight.Click += btnEditWeight_Click;
            // 
            // btnDijkstra
            // 
            btnDijkstra.Location = new Point(723, 643);
            btnDijkstra.Margin = new Padding(4, 5, 4, 5);
            btnDijkstra.Name = "btnDijkstra";
            btnDijkstra.Size = new Size(133, 35);
            btnDijkstra.TabIndex = 6;
            btnDijkstra.Text = "Дейкстра";
            btnDijkstra.UseVisualStyleBackColor = true;
            btnDijkstra.Click += btnDijkstra_Click;
            // 
            // txtX
            // 
            txtX.Location = new Point(16, 708);
            txtX.Margin = new Padding(4, 5, 4, 5);
            txtX.Name = "txtX";
            txtX.Size = new Size(65, 27);
            txtX.TabIndex = 7;
            // 
            // txtY
            // 
            txtY.Location = new Point(89, 708);
            txtY.Margin = new Padding(4, 5, 4, 5);
            txtY.Name = "txtY";
            txtY.Size = new Size(65, 27);
            txtY.TabIndex = 8;
            // 
            // txtVertex
            // 
            txtVertex.Location = new Point(194, 708);
            txtVertex.Margin = new Padding(4, 5, 4, 5);
            txtVertex.Name = "txtVertex";
            txtVertex.Size = new Size(65, 27);
            txtVertex.TabIndex = 9;
            // 
            // txtSrc
            // 
            txtSrc.Location = new Point(320, 708);
            txtSrc.Margin = new Padding(4, 5, 4, 5);
            txtSrc.Name = "txtSrc";
            txtSrc.Size = new Size(65, 27);
            txtSrc.TabIndex = 10;
            // 
            // txtDest
            // 
            txtDest.Location = new Point(440, 708);
            txtDest.Margin = new Padding(4, 5, 4, 5);
            txtDest.Name = "txtDest";
            txtDest.Size = new Size(65, 27);
            txtDest.TabIndex = 11;
            // 
            // txtWeight
            // 
            txtWeight.Location = new Point(606, 708);
            txtWeight.Margin = new Padding(4, 5, 4, 5);
            txtWeight.Name = "txtWeight";
            txtWeight.Size = new Size(65, 27);
            txtWeight.TabIndex = 12;
            // 
            // txtStartVertex
            // 
            txtStartVertex.Location = new Point(760, 708);
            txtStartVertex.Margin = new Padding(4, 5, 4, 5);
            txtStartVertex.Name = "txtStartVertex";
            txtStartVertex.Size = new Size(65, 27);
            txtStartVertex.TabIndex = 13;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(41, 683);
            label1.Margin = new Padding(4, 0, 4, 0);
            label1.Name = "label1";
            label1.Size = new Size(18, 20);
            label1.TabIndex = 14;
            label1.Text = "X";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(107, 683);
            label2.Margin = new Padding(4, 0, 4, 0);
            label2.Name = "label2";
            label2.Size = new Size(17, 20);
            label2.TabIndex = 15;
            label2.Text = "Y";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(194, 688);
            label3.Margin = new Padding(4, 0, 4, 0);
            label3.Name = "label3";
            label3.Size = new Size(73, 20);
            label3.TabIndex = 16;
            label3.Text = "Вершина";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(320, 683);
            label4.Margin = new Padding(4, 0, 4, 0);
            label4.Name = "label4";
            label4.Size = new Size(51, 20);
            label4.TabIndex = 17;
            label4.Text = "Исход";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(427, 683);
            label5.Margin = new Padding(4, 0, 4, 0);
            label5.Name = "label5";
            label5.Size = new Size(94, 20);
            label5.TabIndex = 18;
            label5.Text = "Назначение";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(624, 683);
            label6.Margin = new Padding(4, 0, 4, 0);
            label6.Name = "label6";
            label6.Size = new Size(33, 20);
            label6.TabIndex = 19;
            label6.Text = "Вес";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(723, 683);
            label7.Margin = new Padding(4, 0, 4, 0);
            label7.Name = "label7";
            label7.Size = new Size(147, 20);
            label7.TabIndex = 20;
            label7.Text = "Стартовая вершина";
            // 
            // GraphForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1099, 740);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(txtStartVertex);
            Controls.Add(txtWeight);
            Controls.Add(txtDest);
            Controls.Add(txtSrc);
            Controls.Add(txtVertex);
            Controls.Add(txtY);
            Controls.Add(txtX);
            Controls.Add(btnDijkstra);
            Controls.Add(btnEditWeight);
            Controls.Add(btnRemoveEdge);
            Controls.Add(btnAddEdge);
            Controls.Add(btnRemoveVertex);
            Controls.Add(btnAddVertex);
            Controls.Add(pictureBox);
            Margin = new Padding(4, 5, 4, 5);
            Name = "GraphForm";
            Text = "Graph Visualization";
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
            PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Button btnAddVertex;
        private System.Windows.Forms.Button btnRemoveVertex;
        private System.Windows.Forms.Button btnAddEdge;
        private System.Windows.Forms.Button btnRemoveEdge;
        private System.Windows.Forms.Button btnEditWeight;
        private System.Windows.Forms.Button btnDijkstra;
        private System.Windows.Forms.TextBox txtX;
        private System.Windows.Forms.TextBox txtY;
        private System.Windows.Forms.TextBox txtVertex;
        private System.Windows.Forms.TextBox txtSrc;
        private System.Windows.Forms.TextBox txtDest;
        private System.Windows.Forms.TextBox txtWeight;
        private System.Windows.Forms.TextBox txtStartVertex;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
    }
}
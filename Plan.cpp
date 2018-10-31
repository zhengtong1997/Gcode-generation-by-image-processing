#include "image_gcode.h"
//����

//��������

//-----------------------------------��·���滮��---------------------------------- 
//Ѱ�����ŵ㲿�֣���ȷ
void plan(vector< vector<Point> > &lunkuo, Mat & chushitu, FILE *fp)
{

	Scalar color = Scalar(255, 255, 255);//��ɫ����
	Point origin;
	origin.x = 0;
	origin.y = 0;//����ԭ��
	Point * p = new  Point[2 * lunkuo.size()];//����һ������ÿ��·������յ�Ķ�ά���飬���е�һ�д����ÿ�ε���㣬�ڶ��д���ÿ�ε��յ�
	int * lunkuonum = new  int[lunkuo.size()];//�������������ӵ�������ŵ�����
	for (int i = 0; i < lunkuo.size(); i++)
		lunkuonum[i] = -1;//���pointandlunkuo����д�Ĵ���
	int* diannum1 = new  int[lunkuo.size()];//���������������յ�ĵ����
	int* qidianlunkuo = new  int[lunkuo.size()];//������㣬��������
	int* qidiandian = new  int[lunkuo.size()];
	double *a = pointandlunkuo(origin, lunkuo, lunkuonum, lunkuo.size());//����ԭ��
	lunkuonum[0] = int(a[0]);
	diannum1[0] = int(a[1]);
	p[0] = origin;
	p[1] = lunkuo[lunkuonum[0]].at(diannum1[0]);//��һ��������յ�ȷ��
	double a1 = 0.0;
	double a2 = 0.0;
	double minjuli;
	int qidianlunkuo1;
	int qidiandian1;


	//һϵ�ж��壬Ϊ����õ��ľ��룬��Ĵ��濪�ٿռ�
	for (int g = 1; g <= (lunkuo.size() - 1); g++)//�������Ĵ�����������С������prim�㷨����ȷ��ÿһ�����ӵ������յ����ӵ�������ź͵����
	{
		
		int tiaoshi;



		for (int k = 0; k <g; k++)//���μ����Ѿ����ӵ�������δ���ӵ�����
		{

			for (int i = 0; i < lunkuo[lunkuonum[k]].size(); i = i + DISTANCE)//��������˵�Ĵ���������������ŵ�����ĵ�һ��Ԫ�ؿ�ʼ��
			{
				double *chucun = pointandlunkuo(lunkuo[lunkuonum[k]].at(i), lunkuo, lunkuonum, lunkuo.size());//�о�����Ӧ�ó�������ط���
				double w1 = chucun[0];
				double w2 = chucun[1];
				double w3 = chucun[2];


				if ((k == 0) && (i == 0))//��һ�μ��㴢���ʼ��
				{
					minjuli = chucun[2];
					a1 = chucun[0];
					a2 = chucun[1];
					qidianlunkuo1 = lunkuonum[k];//�������
					qidiandian1 = i;
				}
				else
				{
					double xiangbijuli = chucun[2];//֮��ļ�����ݴ�С��������յ�
					if (xiangbijuli < minjuli)
					{
						minjuli = xiangbijuli;
						a1 = chucun[0];
						a2 = chucun[1];
						qidianlunkuo1 = lunkuonum[k];
						qidiandian1 = i;
					}
				}

			}
		}


		{
			lunkuonum[g] = a1;
			diannum1[g] = a2;
			qidianlunkuo[g] = qidianlunkuo1;
			qidiandian[g] = qidiandian1;
			p[2 * g] = lunkuo[qidianlunkuo[g]].at(qidiandian[g]);

			//circle(srcImage, p[2 * g], 3, Scalar(0, 255, 0), -1, 8, 0);
			p[2 * g + 1] = lunkuo[lunkuonum[g]].at(diannum1[g]);//��ԭ��õ��ĳ��ȱȽ�
																//circle(srcImage, p[2 * g + 1], 3, Scalar(0, 0, 255), -1, 8, 0);
		
			//printf("\n\n��Gcode���£���\ng28\nG1 X%.3f Y%.3f F3600\nG1 Z0.300 F3600.000\nG1 E0.50000 F1800.000\n", (vContours[i].at(j).x) / 1000, (vContours[i].at(j).y) / 1000);
			//fprintf(fp, "G28\nG1 X%.3f Y%.3f F3600\nG1 Z0.30 F3600.000\nG1 E0.50000 F1800.000\n",
				//(vContours[i].at(j).x) / 1000, (vContours[i].at(j).y) / 1000);
			//line(srcImage, p[0], p[1], Scalar(255, 0, 0), 0, 8);
			//line(srcImage, p[2 * g], p[2 * g + 1], Scalar(255, 0, 0), 0, 8);
			tiaoshi = lunkuonum[g];
			;

		}


	}

	int ap = 0;
	int aq = 0;
	fuzhu(lunkuonum, lunkuo.size(), diannum1, lunkuo.size(), qidianlunkuo, lunkuo.size(), qidiandian, lunkuo.size());//
	for (int i = 0; i < lunkuo.size(); i = i + 1)
	{
		ap = qidianlunkuo[i];
		aq = qidiandian[i];
	}
	//����������Ƭͼ���֣���ȷ
	Mat yhqiepian = Mat::zeros(chushitu.size(), CV_8UC3); //Ŀ��ͼ������

	//line(yhqiepian, p[0], p[1], color, 0, 8);
	//printf("\n\n��Gcode���£���\ng28\nG1 X%.3f Y%.3f F3600\nG1 Z0.300 F3600.000\nG1 E0.50000 F1800.000\n", (vContours[i].at(j).x) / 1000, (vContours[i].at(j).y) / 1000);
	//fprintf(fp, "G28\nG1 X%u Y%u F3600\nG1 Z0.30 F3600.000\nG1 E0.50000 F1800.000\n",
	fprintf(fp, "G28\nG1 X%u Y%u F3600\n",
		(p[1].x) /hh, (p[1].y) / hh);
	int x0 = p[1].x;
	int y0 = p[1].y;
	int qi1 = 1;
	int qi2 = 0;
	int tiaoship;
	int tiaoshipp;

	do

	{
		int  * zhong = paixu(qi1, qi2, yhqiepian, lunkuo, lunkuonum, lunkuo.size(), diannum1, lunkuo.size(), qidianlunkuo, lunkuo.size(), qidiandian, lunkuo.size());
		tiaoship = zhong[0];
		tiaoshipp = zhong[1];
		int tiaoshi3 = zhong[3];
		int tiaoshi2 = zhong[2];
		if (qi1 == 1 && tiaoshi3 == 1)//������յ㣬�յ�Ҳ���յ�vContours[i].at(j + DISTANCE),
									  //circle(drawing, lunkuo[lunkuonum[qi2]].at(diannum1[qi2]), 3, Scalar(255, 255, 255), -1, 8, 0);
			huaxian(lunkuonum[qi2], diannum1[qi2], lunkuonum[tiaoshi2], diannum1[tiaoshi2], yhqiepian, lunkuo,fp);
		else if (qi1 == 0 && tiaoshi3 == 1)//�������㣬�յ�Ҳ���յ�
										   //circle(drawing, lunkuo[lunkuonum[qi2]].at(diannum1[qi2]), 3, Scalar(255, 255, 255), -1, 8, 0);
			huaxian(qidianlunkuo[qi2], qidiandian[qi2], lunkuonum[tiaoshi2], diannum1[tiaoshi2], yhqiepian, lunkuo, fp);
		else if (qi1 == 1 && tiaoshi3 == 0)//������յ㣬�յ�Ҳ�����
			huaxian(lunkuonum[qi2], diannum1[qi2], qidianlunkuo[tiaoshi2], qidiandian[tiaoshi2], yhqiepian, lunkuo, fp);
		else//�������㣬�յ�Ҳ�����
			huaxian(qidianlunkuo[qi2], qidiandian[qi2], qidianlunkuo[tiaoshi2], qidiandian[tiaoshi2], yhqiepian, lunkuo, fp);



		if (tiaoship != lunkuonum[0] || tiaoshipp != diannum1[0])
		{
			if (tiaoshi3 == 1)
			{
				huaxian(tiaoship, tiaoshipp, qidianlunkuo[tiaoshi2], qidiandian[tiaoshi2], yhqiepian, lunkuo, fp);
				qi1 = 0;
				qi2 = tiaoshi2;
			}
			else
			{
				huaxian(tiaoship, tiaoshipp, lunkuonum[tiaoshi2], diannum1[tiaoshi2], yhqiepian, lunkuo, fp);
				qi1 = 1;
				qi2 = tiaoshi2;
			}
		}

	} while (tiaoship != lunkuonum[0] || tiaoshipp != diannum1[0]);
	


	delete[] lunkuonum;
	delete[] diannum1;
	delete[] qidianlunkuo;
	delete[] qidiandian;
	Point tiaoshi1 = p[5];

	delete[] p;


	return;
}
void huaxian(int qdlknum, int qddnum, int zdlknum, int zddnum, Mat & yhqiepian, vector< vector<Point> > &lunkuo, FILE *fp)
{
	float E = 0.5;//���������
	Scalar color = Scalar(255, 255, 255);
	if (qdlknum == zdlknum)
	{
		if (zddnum == qddnum)
		{
			for (unsigned int i = qddnum; i < (lunkuo[qdlknum].size() - DISTANCE); i = i + DISTANCE)
			{
				//line(yhqiepian, lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE), color, 0, 8);
				// ��ʾЧ��ͼ���ʱ��
				//imshow("��Ƭͼ", yhqiepian);//��̬��ʾͼƬ
				//E = CalculateDistance(lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE));
				//printf("G1 X%.3f Y%.3f E0%.5f F600\n", vContours[i].at(j).x, vContours[i].at(j).y, E);
				fprintf(fp, "G1 X%u Y%u F600\n", (lunkuo[qdlknum].at(i))/hh, (lunkuo[qdlknum].at(i + DISTANCE))/hh, E);
				
			}
			for (int i = 0; i < (zddnum - DISTANCE); i = i + DISTANCE)
			{
				//line(yhqiepian, lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE), color, 0, 8);
				// ��ʾЧ��ͼ���ʱ��
				//imshow("��Ƭͼ", yhqiepian);//��̬��ʾͼƬ
				//E = CalculateDistance(lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE));
				//printf("G1 X%.3f Y%.3f E0%.5f F600\n", vContours[i].at(j).x, vContours[i].at(j).y, E);
				fprintf(fp, "G1 X%u Y%u F600\n", (lunkuo[qdlknum].at(i)) / hh, (lunkuo[qdlknum].at(i + DISTANCE)) / hh, E);
				
			}
		}
		else if (zddnum < qddnum)
		{
			for (unsigned int i = qddnum; i < (lunkuo[qdlknum].size() - DISTANCE); i = i + DISTANCE)
			{
				//line(yhqiepian, lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE), color, 0, 8);
				// ��ʾЧ��ͼ���ʱ��
				//imshow("��Ƭͼ", yhqiepian);//��̬��ʾͼƬ
				//E = CalculateDistance(lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE));
				//printf("G1 X%.3f Y%.3f E0%.5f F600\n", vContours[i].at(j).x, vContours[i].at(j).y, E);
				fprintf(fp, "G1 X%u Y%u F600\n", (lunkuo[qdlknum].at(i)) / hh, (lunkuo[qdlknum].at(i + DISTANCE)) / hh, E);
				
			}
			for (int i = 0; i <(zddnum - DISTANCE); i = i + DISTANCE)
			{
				//line(yhqiepian, lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE), color, 0, 8);
				// ��ʾЧ��ͼ���ʱ��
				//imshow("��Ƭͼ", yhqiepian);//��̬��ʾͼƬ
				//E = CalculateDistance(lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE));
				//printf("G1 X%.3f Y%.3f E0%.5f F600\n", vContours[i].at(j).x, vContours[i].at(j).y, E);
				fprintf(fp, "G1 X%u Y%u F600\n", (lunkuo[qdlknum].at(i)) / hh, (lunkuo[qdlknum].at(i + DISTANCE)) / hh, E);
				
			}
		}
		else
			for (int i = qddnum; i <(zddnum - DISTANCE); i = i + DISTANCE)
			{
				//line(yhqiepian, lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE), color, 0, 8);
				// ��ʾЧ��ͼ���ʱ��
				//imshow("��Ƭͼ", yhqiepian);//��̬��ʾͼƬ
				//E = CalculateDistance(lunkuo[qdlknum].at(i), lunkuo[qdlknum].at(i + DISTANCE));
				//printf("G1 X%.3f Y%.3f E0%.5f F600\n", vContours[i].at(j).x, vContours[i].at(j).y, E);
				fprintf(fp, "G1 X%u Y%u F600\n", (lunkuo[qdlknum].at(i)) / hh, (lunkuo[qdlknum].at(i + DISTANCE)) / hh, E);
		
			}
	}
	else
	{
		//line(yhqiepian, lunkuo[qdlknum].at(qddnum), lunkuo[zdlknum].at(zddnum), color, 0, 8);

		//imshow("��Ƭͼ", yhqiepian);//��̬��ʾͼƬ
		//E = CalculateDistance(lunkuo[qdlknum].at(qddnum), lunkuo[zdlknum].at(zddnum));
		//printf("G1 F1800.000 E%.5f\nG1 Z2.300 F3600.000\nG92 E0\nG1 X%.3f Y%.3f F3600.000\nG1 Z0.300 F3600.000\nG1 E0.50000 F1800.000\n ", vContours[i].at(j).x, vContours[i].at(j).y, E);
		fprintf(fp, "G1 X%u Y%u F3600.000\n",
			(lunkuo[qdlknum].at(qddnum))/hh, (lunkuo[zdlknum].at(zddnum))/hh, E);
	
	}
	return;

}
double * pointandlunkuo(Point& point, vector< vector<Point> > & lunkuo, int w[], int n)//�ú����Ǽ���һ�������δ���ӵ���������̾��� 
																					   //�����е㣬�����ļ��ϣ������Ѿ����ӵĵ����ŵ�����ʹ�С����ȷ
{
	double * d = new double[lunkuo.size()];//����һ����������С�����飬��������㵽�����ľ���
	double a[3];//����һ��3ά���飬�����������յõ���һ�����������������ϵĵ㣨�����ӵ��յ㣩����������С
	a[2] = 0.0;
	int k = 0;
	double dnew;
	int f = 0;
	int biaoji = 0;
	for (int i = 0; i < lunkuo.size(); i++)
	{

		for (int u = 0; u < lunkuo.size(); u++)//����һ��ѭ�������жϴ�ʱ��i����������Ƿ��Ѿ����ӣ������ӣ�������һ��ѭ����i+1
			if (i == w[u])
				//goto sameend;
				biaoji = 1;
		if (biaoji == 0)
		{


			for (int j = 0; j < lunkuo[i].size(); j = j + DISTANCE)//������õ㵽��i����������̾�����յ�
			{
				if (j == 0)
				{
					d[i] = CalculateDistance(point, lunkuo[i].at(0));

					if (k == 0)
					{
						a[2] = d[i];
						a[0] = i;
						a[1] = j;
					}
				}//��ʼ���봢��
				dnew = CalculateDistance(point, lunkuo[i].at(j));//ѭ���õ����¾��� 
				if (d[i] > dnew)//�Ƚϴ�С 
				{
					d[i] = dnew;
					if (k > 0)//���k>0����˵����ʱ�Ѿ�����������һ��������������ʱ���������Ľ����ǰһ������Ƚ�
					{
						if (d[i] < a[2])//��diС����ʱ��͸����յ���Ϣ
						{
							a[0] = i;
							a[1] = j;
							a[2] = d[i];
						}
					}
					else//����Ӧ����i=0���ǾͰ��յ���Ϣ��������
					{
						a[0] = i;
						a[1] = j;
						a[2] = d[i];
					}
				}
			}
			k++;
			//if (f > 0)
			//f = 0;
		}

		biaoji = 0;
	}
	delete[] d;
	return a;
}
double CalculateDistance(Point & Point1, Point  &Point2)//��ȡ����
{
	double ds;
	ds = sqrt((double)((Point1.x - Point2.x)*(Point1.x - Point2.x) + (Point1.y - Point2.y)*(Point1.y - Point2.y)));
	return ds;
}
int * paixu(int p, int xuhao, Mat & yhqiepian, vector< vector<Point> > &lunkuo, int lunkuonum[], int lm, int diannum1[], int dm, int qidianlunkuo[], int qlm, int  qidiandian[], int qdm)
{
	int b[4];
	int re;
	int jilui = 0;
	int jilui1 = 0;
	int kd = 0;
	int kx = 0;
	int kx1 = 0;
	int kd1 = 0;
	int jiluii = 0;
	int jilui11 = 0;
	int qdlknum;
	int qddnum;
	if (p == 1)
	{
		qdlknum = lunkuonum[xuhao];
		qddnum = diannum1[xuhao];
	}
	else
	{
		qdlknum = qidianlunkuo[xuhao];
		qddnum = qidiandian[xuhao];
	}
	for (int i = 0; i < lm; i++)
		if (qdlknum == lunkuonum[i])

		{
			if (diannum1[i] > qddnum)
			{
				if (kd == 0)
					jilui = i;//��ʼ��
				else if (diannum1[i] < diannum1[jilui])
					jilui = i;//����
				kd++;
			}
			else if (diannum1[i] < qddnum)
			{
				if (kx == 0)
					jiluii = i;//��ʼ��
				else if (diannum1[i] < diannum1[jiluii])
					jiluii = i;//����
				kx++;
			}
		}
	for (int i = 0; i < lm; i++)
		if (qdlknum == qidianlunkuo[i])

		{
			if (qidiandian[i] >qddnum)
			{
				if (kd1 == 0)
					jilui1 = i;
				else if (qidiandian[i] < qidiandian[jilui1])
					jilui1 = i;
				kd1++;
			}
			else if (qidiandian[i] < qddnum)
			{
				if (kx1 == 0)
					jilui11 = i;
				else if (qidiandian[i] < qidiandian[jilui11])
					jilui11 = i;
				kx1++;
			}
		}
	if ((kx == 0) && (kd == 0) && (kx1 == 0) && (kd1 == 0))
	{
		if (p == 1)
		{
			b[0] = lunkuonum[xuhao];
			b[1] = diannum1[xuhao];
			b[2] = xuhao;
			b[3] = p;
		}
		else
		{
			b[0] = qidianlunkuo[xuhao];
			b[1] = qidiandian[xuhao];
			b[2] = xuhao;
			b[3] = p;
		}


	}
	else if (kd > 0 && kd1>0)
	{
		if (qidiandian[jilui1]< diannum1[jilui])
		{
			b[0] = qidianlunkuo[jilui1];
			b[1] = qidiandian[jilui1];
			b[2] = jilui1;
			b[3] = 0;
		}
		else
		{
			b[0] = lunkuonum[jilui];
			b[1] = diannum1[jilui];
			b[2] = jilui;
			b[3] = 1;
		}
	}
	else if (kd>0)
	{
		b[0] = lunkuonum[jilui];
		b[1] = diannum1[jilui];
		b[2] = jilui;
		b[3] = 1;
	}
	else if (kd1>0)
	{
		b[0] = qidianlunkuo[jilui1];
		b[1] = qidiandian[jilui1];
		b[2] = jilui1;
		b[3] = 0;
	}
	else if (kx > 0 && kx1 > 0)
	{
		if (qidiandian[jilui11] <diannum1[jiluii])
		{
			b[0] = qidianlunkuo[jilui11];
			b[1] = qidiandian[jilui11];
			b[2] = jilui11;
			b[3] = 0;
		}
		else
		{
			b[0] = lunkuonum[jiluii];
			b[1] = diannum1[jiluii];
			b[2] = jiluii;
			b[3] = 1;
		}
	}
	else if (kx>0)
	{
		b[0] = lunkuonum[jiluii];
		b[1] = diannum1[jiluii];
		b[2] = jiluii;
		b[3] = 1;
	}
	else if (kx1>0)
	{
		b[0] = qidianlunkuo[jilui11];
		b[1] = qidiandian[jilui11];
		b[2] = jilui11;
		b[3] = 0;
	}
	return b;
}
//���غϵĵ㰴һ����λ���룬�Ա��ں���Ĳ������������������㹻С����ȷ
void fuzhu(int lunkuonum[], int lm, int diannum1[], int dm, int qidianlunkuo[], int qlm, int  qidiandian[], int qdm)
{

	for (int i = 0; i < lm; i++)
		for (int j = i + 1; j < lm; j++)
		{
			int k = 0;
			if ((qidianlunkuo[i] == qidianlunkuo[j]) && (qidiandian[i] == qidiandian[j]))
			{
				k++;
				qidiandian[j] = qidiandian[j] + k;
			}
		}
	for (int i = 0; i < lm; i++)
		for (int j = 0; j < lm; j++)
		{
			if ((qidianlunkuo[i] == lunkuonum[j]) && (qidiandian[i] == diannum1[j]))
			{

				diannum1[j] = diannum1[j] + 1;
			}
		}


}

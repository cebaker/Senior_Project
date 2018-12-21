#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sendData.h"
#include "wav.c"



//global Declarations for 2D Arrays variabls
int layer1_row_ar1 = 40;
int layer1_col_ar1 = 10;
int layer1_row_ar2 = 10;
int layer1_col_ar2 = 1;

int layer2_row_ar1 = 2;
int layer2_col_ar1 = 40;
int layer2_row_ar2 = 40;
int layer2_col_ar2 = 1;


double  w1[40][10] = {
		{0.361770151546112,0.764483261677570,0.190917535640086,0.661780887595217,-0.177023538010417,-1.09098667018922,-2.56032755098060,0.204524520853458,-0.794996693727124,-1.09930395764204},
		{0.0389706675097839,-0.0290166880102636,-1.62550867753395,1.23327716250541,0.678974630315514,-1.05091002746492,0.140406810998038,-0.546330399510189,-1.29692676811603,0.0710894075240598},
		{0.946294327527726,0.341522170753401,1.52429923050150,0.689794933694478,0.607098585798099,-0.662764147755228,-0.172637263048989,-0.610050799987087,-1.23608305910750,1.88417685304128},
		{0.107338098876574,-1.02253985657429,0.309321018495394,0.206514196148989,1.68574889439514,0.738415276986977,0.364012389613297,1.18186685679914,0.421662035091985,0.0239809284311595},
		{-2.71380990664245,0.680782639614804,0.637005573987653,0.528885186587504,-0.753261698534449,0.847622452361712,-0.526969777078996,0.689392091540078,-0.397416953850993,0.0891944911332076},
		{-0.492358051463172,-0.484159791552885,-0.139524530884490,-2.78182981236194,-1.38898055458282,0.0782177686821270,-1.09248250393463,-0.727217323104700,0.760776461101872,0.941259785463528},
		{1.30017023053011,0.0139014180068044,0.257072271979682,0.477448703702687,-1.46389005157435,1.24139915487978,-0.185430303941484,0.876113469795999,0.171939096712079,0.613494068873998},
		{1.04519030818341,2.23000480036650,-0.0681501262215647,0.402637432696811,0.432743297056166,-0.190465209991655,0.321247988438375,-0.366459679417529,-0.659758926368674,-0.0355670725498697},
		{1.97528385444265,-0.0851262573467165,-0.261955523168383,0.947875082175010,0.182916749939721,0.632745240790399,-0.890594378115442,-0.617107603982034,-0.436629216927096,0.305677403943385},
		{-0.783069012168627,0.0841029240340057,1.24601794118148,-0.311536551684371,0.325954274959948,-1.00890419886554,-1.25299794955716,-0.0190093466221972,-0.757234822542683,0.833301439086606},
		{1.18164991655586,-2.52091712487506,0.0965579585670022,0.239342148825306,0.399316548629863,0.400223801944104,-0.393976635473984,-0.980956367105967,0.354318305439377,0.116706280722612},
		{0.170539162705558,0.887655546159498,-1.09287855042187,-0.0801619104679479,-0.297496455221590,0.234519322554531,-1.70325858859833,-0.405222467808965,-0.238943511123661,-1.02057819767616},
		{0.706967955318991,1.60407336726660,0.568189265207519,-1.47282584539174,-1.72046795824048,-0.456806527769043,-1.82919597355902,-0.516769769744607,0.827287076006911,1.13931968984314},
		{0.316413954671396,-1.15588739335294,-0.771708347040435,1.62477176664262,0.199089954646939,-0.359355031473650,-1.88581073534175,-0.282864742214926,-3.02818765545244,0.227852207751628},
		{0.600130401327666,-0.159779715019191,-0.798722290516173,-2.24794405093437,1.40577202572518,0.532472029099801,0.276169676451769,-0.151846542389460,1.67810333618530,-0.0480233723145907},
		{0.242505269161502,-0.737250573294288,-0.566485103749008,0.0256431676779772,-1.20238082093633,0.893422483568497,0.167937003306738,1.97045548182881,-1.13813852751677,1.12652615976925},
		{-0.402040719283427,-1.96024359831391,1.03951759017865,-1.00987256859555,0.745533460781003,-1.36684462838942,-0.0284499124701598,0.840074683229051,0.900017892046673,-1.71988989335949},
		{-2.37778215843831,-1.35835464056786,0.141284756928965,0.741135419777546,1.37739466547246,-0.539168742231217,3.22893061450153,-0.490986376589231,-1.85728639133180,1.20932097206229},
		{-1.23306077584146,-0.0349916855751679,-1.12788409775686,0.0255791600161840,-0.887565193851547,1.34499791346231,0.438202011458608,0.955023618974466,0.673827399910515,0.180660208200601},
		{-1.54812591388613,0.0203827107202071,-0.323235792748598,-2.16944039597636,-0.0241862815154329,0.607388363084450,0.636474116209966,0.823988628419886,-1.20540487003199,0.506722922055590},
		{-0.478940564007277,0.691086328764572,0.593808118504300,1.37691572399054,0.262217288790774,2.02836514366470,-0.190333862590916,0.953704237193307,2.34069502647565,0.954626502947423},
		{-2.48635521108821,-0.378672476406821,-0.0286831120837533,-0.520713232961424,1.26793811188076,-0.293809637022819,-1.62419257479405,-0.0292210261891422,-0.0157940710431574,-1.58524331754697},
		{0.313893027813560,-0.488655882025095,-0.401941740270508,-1.36666913109514,1.22773100776620,-0.103207579395771,1.27356259079381,-1.35597411595289,0.130003155887996,1.92578764004932},
		{0.971299985161262,1.55467229613276,-2.14262861848646,-0.772726468496614,0.128535141940186,-0.204227235779990,1.16501489846534,0.620560188256146,-0.794745127525208,-0.134599389962394},
		{-1.47046274872987,-0.189510473025372,-1.71231484081859,0.333339071928572,-0.111063174718925,-0.0388956455515130,0.842586198249142,0.508263694136842,-0.434834659012538,-2.41228202960024},
		{-0.154929748951489,-0.846517826273631,0.0858894435991327,-0.102564706742113,-0.312199692311599,1.30305518569816,-1.97653645521176,-1.06695980299115,-0.0294221755321541,-1.68083983995053},
		{-0.509650867294257,0.505696337852395,-1.80894956565636,-2.78600129914025,0.189580592179484,1.03578032621021,0.686725142048817,1.87219555373774,0.0235904952938030,1.27256699189961},
		{-0.474330975819626,0.559040282937219,-0.478211257058079,1.44683575198925,-1.76810468324227,4.09024235661408,0.336475601996032,-0.346730797443227,-0.173702035891774,0.180144437289461},
		{0.760238186890049,-0.0838241182811239,-0.340064393178819,-0.0727250186314476,0.727562121965862,1.42556632779338,2.13710028302747,0.755622166670469,-1.37325789841608,-0.0367901015496560},
		{-0.266398765809341,0.00565770631373323,-0.643395692610504,1.03705609566196,2.34996493374453,-2.08743312894457,0.0758421146282613,-1.00743320428367,-1.13299261809303,0.339929123070524},
		{-0.571824777572937,-0.680167134247549,-0.946416714915084,1.07669176799936,1.12055893046027,-0.665962405471664,-0.691576074697401,1.40974633563166,0.433685510352095,-0.976354421298064},
		{-1.11438258884445,1.30359800273866,0.957073856677709,0.677022466363626,-1.39048253789898,0.291326817640972,-0.904438014782893,-0.343088253453162,0.360368525081437,0.385430210670438},
		{0.0949191234882293,0.145641658728474,-1.65033514734634,0.165276310939419,1.38366159569619,-0.658906694425275,-0.308492397468631,-0.552359340495316,-0.854038767386343,-0.524884687589710},
		{0.256591885795770,0.662974581181398,0.904659309985340,1.69152395723620,-1.44678106136716,-0.239956623045683,-0.449013561146862,0.768023744433515,1.68868567471249,0.269283630864063},
		{0.0855066763621159,1.11526760018929,-0.284836162360938,-1.41872068888915,1.29071111285535,-0.0697090571362556,1.08818150773284,-0.226522581666624,0.0441552829217503,1.61088365876413},
		{0.353991904112904,0.710163517113688,-0.272313260374750,-0.658603838344886,0.0547256741948116,-0.446064003728588,2.26258372922922,1.70271801603163,1.46288025260997,0.630901720690466},
		{0.732294445699200,-2.07286682061211,0.631051675653977,-1.28645291559504,-1.49163895785974,-1.81161651925232,-1.22631534689367,1.83529652634619,-0.697002799988798,1.40412863819170},
		{0.892660447791995,1.03765128352414,0.630510474268390,-0.320929280478297,-0.947740828865493,0.126147469732045,-0.149022529387895,0.150496186909080,1.72578345140010,1.27262297110980},
		{-0.565908678421276,-0.513615887287434,3.01314177273620,-1.65180762370870,0.0779526133979684,-1.02866452639326,-0.215181224831239,2.53159147144772,0.285643509342930,0.0885509764526308},
		{0.178514396671873,0.125293318804292,-1.48862882004716,1.22710142721136,0.863698075269660,0.233441912631363,-1.81429627252191,-0.619496065213549,0.569381639425077,-0.234154403661950}};
double  w2[2][40] = {
			{-1.08302221311432,1.10533090119554,1.01109017693655,1.42866063319171,-0.955135202911004,0.482093557779923,-1.36442525547381,-1.96428024442520,0.591062672208493,1.54782241523222,1.39841109233595,0.0192519334445875,0.0110223294271939,0.517595642011705,-0.971961884360957,-1.15178659410982,0.341459070261278,1.80857330031646,0.316674197512336,-0.176619372345797,-0.657603000564153,-1.18057961974864,0.571352079121756,0.661880261183896,-0.975301396813019,-0.233959434239413,-0.256542555101684,-1.45332867444692,-0.374974172108556,0.257418815714068,0.386118571800870,-1.14875019341576,0.209485464545436,-0.436234440184388,0.699220794164274,0.0195493899772528,1.86572079016350,1.41977614651121,1.18348053455412,-2.52111697498668},
			{-1.40412978030586,-0.199300512851663,-0.513169529521390,0.347241057828490,0.802468422176919,-1.34319443084999,0.230951357424215,0.0353820881461431,0.342576032715242,-0.132225190270958,-0.348507680058076,0.152596874740638,-0.875419638610211,-0.593372919495747,2.76047985602529,-2.08127249106911,-1.11311578238993,0.508198477097061,-0.220375512304802,-1.59398400897981,1.10082501913255,-0.765683774582285,0.486257246496039,1.14667454512499,2.86811853518717,0.916335708497231,0.475579143658425,0.372089091904583,-1.42950930386756,-2.31261544811249,1.01718203742180,0.609799286856276,-0.577278069371369,-1.04458801880846,1.16334431816893,-0.356340490638526,-1.51174847974340,1.06497687645566,1.46292114857906,0.481363961603876}};


double networkout_val[2][1];
double sigmoid(double x);
void destroyArray(double** arr);

double ** createArray(int m, int n);
void  print(int , int ,double **);
double ** layer1out(int , int,double [layer1_row_ar1][layer1_col_ar1]);
double ** networkout(int , int,double [layer2_row_ar1][layer2_col_ar1] );

void nueralNet(double *);
double ** matrixMultiply_t1(double [layer1_row_ar1][layer1_col_ar1], double [layer1_row_ar2]);
double ** matrixMultiply_t2(double [layer2_row_ar2][layer2_col_ar2], double [layer2_row_ar2][layer2_col_ar2 ]);

void numdecide();
void main(){
    double * dataAry;
    dataAry = getData();
   
    double features[24];
    double features_2bit[10];
	
	melfunction_initialize();

    extractFeatures( dataAry,features);
    for(int i = 0 ; i < 10; i++){
    	 features_2bit[i] = features[i];

     } 
 
      melfunction_terminate();
      for(int i = 0; i < 10; i++){
      	if(i != 9){
      		printf("%f ",features_2bit[i]);
      	}
      	else{
      		printf("%f",features_2bit[i]);
      	}
      	
      }
     //sendData(features_2bit);
      //nueralNet(features_2bit);

     // numdecide();
}
void numdecide(){
	double tmp_total = 0;
	int networkout[2];
	int value = 0; 
	
    if(networkout_val[0][0] < .5)
    	networkout[0] = 0;
    else
    	networkout[0] = 1;

    if(networkout_val[1][0] < .5)
    	networkout[1] = 0;
    else
    	networkout[1] = 1;
   
    if(networkout[0] == 0 && networkout[1] == 0)
    	printf("I heard ONE.");
    else if(networkout[0] == 0 && networkout[1] == 1)
    	printf("I heard TWO. ");
    else if(networkout[0] == 1 && networkout[1] == 0)
    	printf("I heard THREE. ");
    else if(networkout[0] == 1 && networkout[1] == 1)
    	printf("I heard FOUR. ");
    else
    	printf("Sorry I could not understand. ");
    

}
void nueralNet(double * features){
	double ** tmp;
	double ** layer_tmp;
	double layer1out_val[40][1];
	
	
	double t1[40][1];
	double t2[2][1];

	
	/***************Layer 1 OUTPUT *****************/
	/*This module is for handeling the layer 1 output
	 *and setting the nuerons in the first layer
	 */
	int count = 0;
	tmp = matrixMultiply_t1(w1,features);
	
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 1; j++){
			t1[i][j] = tmp[i][j];
		}
	}

		
			
	destroyArray(tmp);
	layer_tmp = layer1out(40,1,t1);
	
	for(int i = 0; i < 40; i++)
		for(int j = 0; j < 1; j++)
			layer1out_val[i][j] = layer_tmp[i][j];
		
	destroyArray(layer_tmp);	
	
	
	/***************NETWORK OUTPUT *****************/
	tmp = matrixMultiply_t2(w2,layer1out_val);
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 1; j++)
			t2[i][j] = tmp[i][j];
		
	destroyArray(tmp);
	
	layer_tmp = networkout(2,1,t2);
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 1; j++)
			networkout_val[i][j] = layer_tmp[i][j];
	
	print(2,1,layer_tmp);

	destroyArray(layer_tmp);
	
}
//converts dynamic array to static 
double sigmoid(double x)
{
     double exp_value;
     double return_value;

     /*** Exponential calculation ***/
     exp_value = exp((double) -x);

     /*** Final sigmoid value ***/
     return_value = 1 / (1 + exp_value);

     return return_value;
}
void destroyArray(double** arr){
    free(*arr);
    free(arr);
}
double** createArray(int m, int n){
    
	double **arr = (double **)malloc(m * sizeof(double *));
	for (int i=0; i<m; i++)
		arr[i] = (double *)malloc(n * sizeof(double));

	return arr;
}
void print(int m, int n, double ** ary){
    int i, j;
    for (i = 0; i < m; i++){//first array row
      for (j = 0; j < n; j++){//second array column
        printf("%f ", ary[i][j]);
	  }
		printf("\n");
	}


}


double ** layer1out(int m, int n,double t1[40][1]  )
{
	int count = 0;

	double ** layer1_output = createArray(m,n);
    
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			layer1_output[i][j] = sigmoid(t1[i][j]);
		
		}
	}
	
	
	return layer1_output;
}

double ** networkout(int m, int n , double t2[][1] )
{
	int count = 0;
	double ** layer2_output = createArray(m,n);
	
	
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				layer2_output[i][j] = sigmoid(t2[i][j]);	
			}
		}
	return layer2_output;
}

double ** matrixMultiply_t1(double  first[][10] , double second[10]){
  int  c, d, k;
  double  sum = 0;
  double multiply[40][40];
 
	for (c = 0; c < layer1_row_ar1; c++){ 
		for (d = 0; d < layer1_col_ar2; d++){ 
			for (k = 0; k < layer1_row_ar2; k++){ 
				sum = sum + first[c][k]*second[k];
			}
		multiply[c][d] = sum;
		sum = 0;
		}
	}


  double **product = malloc(sizeof *product * layer1_row_ar1);
  if (product)
  {
    for (int i = 0; i < layer1_row_ar1; i++)
    {
    product[i] = malloc(sizeof *product[i] * layer1_col_ar1);
    }
  }

  for (c = 0; c < layer1_row_ar1; c++) 
    for (d = 0; d < layer1_col_ar2; d++)
      product[c][d] = multiply[c][d];
   
 
  
  return product;

}
double ** matrixMultiply_t2(double  first[][40] , double second[][1]){
	int  c, d, k;
	double  sum = 0;
	double multiply[40][40];
	int count;
	
	
	for (c = 0; c < layer2_row_ar1; c++) {
		for (d = 0; d < layer2_col_ar2; d++) {
			for (k = 0; k < layer2_row_ar2; k++) {
				sum = sum + first[c][k]*second[k][d];
			}
			
			multiply[c][d] = sum;
			sum = 0;
		}
	}
	
	
	double **product = malloc(sizeof *product * layer1_row_ar1);
	if (product)
	{
		for (int i = 0; i < layer1_row_ar1; i++)
		{
			product[i] = malloc(sizeof *product[i] * layer1_col_ar1);
		}
	}
	
	for (c = 0; c < layer1_row_ar1; c++) {
		for (d = 0; d < layer2_col_ar2; d++)
			
			product[c][d] = multiply[c][d];
		
	}
	
	return product;
	
}





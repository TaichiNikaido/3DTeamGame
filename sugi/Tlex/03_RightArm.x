xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 123;
 -2.15885;-7.62463;-14.14812;,
 4.33040;-10.22648;-19.14662;,
 8.34275;-26.10137;-22.39642;,
 -0.11755;-22.91067;-18.76572;,
 -0.82425;-15.72802;12.69763;,
 -5.52760;-11.38432;2.58573;,
 -5.78580;-26.86292;-0.68697;,
 4.97915;-32.16798;4.42892;,
 -5.61934;-84.58096;-28.25587;,
 -4.01620;-83.97305;-25.25452;,
 -6.71565;-83.91700;-24.55727;,
 -8.30660;-84.53660;-27.49492;,
 -5.32980;-23.82777;-10.37602;,
 -3.85865;-8.56703;-6.94172;,
 6.60110;-33.77708;-18.96786;,
 8.99945;-35.60419;-7.08607;,
 7.33920;-42.65308;-5.89162;,
 4.95245;-42.06828;-14.33022;,
 4.45640;-37.80322;2.32448;,
 -6.22170;-34.87273;-0.35577;,
 -5.79360;-41.71338;-0.40812;,
 5.45280;-42.99744;0.21013;,
 -5.63530;-32.93228;-8.43073;,
 -0.65850;-32.11272;-16.87517;,
 -1.04485;-41.45387;-14.62597;,
 -5.14740;-41.19878;-7.10278;,
 4.32145;-50.99944;-4.80167;,
 2.22285;-51.01402;-10.22778;,
 -4.68695;-51.24168;0.10158;,
 3.53280;-51.05524;-0.52567;,
 -3.60435;-51.50117;-11.33532;,
 -5.37515;-51.03642;-5.87062;,
 3.57475;-58.51993;-16.37833;,
 5.80580;-62.85693;-20.33961;,
 -0.55505;-62.86798;-21.95576;,
 -2.17085;-58.60463;-17.04617;,
 6.01930;-83.27680;-29.10762;,
 6.26495;-82.60925;-25.37112;,
 3.95770;-82.92585;-25.25471;,
 3.73250;-83.59686;-28.91331;,
 -0.55505;-62.86798;-21.95576;,
 1.37710;-68.26034;-17.06978;,
 -0.48774;-71.95184;-21.00291;,
 -2.84715;-67.67638;-25.29817;,
 -4.95885;-68.94224;-16.41292;,
 -5.89775;-72.65324;-20.17052;,
 -6.52055;-64.79578;-19.97377;,
 -7.94615;-68.93113;-23.74773;,
 6.43310;-67.46154;-18.80582;,
 6.81475;-70.97430;-21.59807;,
 5.50840;-66.86918;-25.13933;,
 1.37710;-68.26034;-17.06978;,
 2.00460;-71.81869;-20.93033;,
 0.17730;-67.46519;-25.68773;,
 2.00460;-71.81869;-20.93033;,
 0.17730;-67.46519;-25.68773;,
 5.80965;-72.00234;-28.71606;,
 7.09020;-74.73135;-23.92812;,
 6.26495;-82.60925;-25.37112;,
 6.01930;-83.27680;-29.10762;,
 7.09020;-74.73135;-23.92812;,
 3.08235;-75.43909;-23.85143;,
 3.95770;-82.92585;-25.25471;,
 6.26495;-82.60925;-25.37112;,
 3.08235;-75.43909;-23.85143;,
 1.78960;-72.76859;-28.55202;,
 3.73250;-83.59686;-28.91331;,
 3.95770;-82.92585;-25.25471;,
 1.78960;-72.76859;-28.55202;,
 5.80965;-72.00234;-28.71606;,
 6.01930;-83.27680;-29.10762;,
 3.73250;-83.59686;-28.91331;,
 -3.81009;-63.40453;-10.32482;,
 -5.67015;-60.57068;-13.34837;,
 -6.52055;-64.79578;-19.97377;,
 -4.95885;-68.94224;-16.41292;,
 1.79140;-62.42113;-11.39282;,
 -2.98260;-1.39503;19.63473;,
 -5.56690;2.79552;8.26928;,
 -4.17760;5.55512;-1.51457;,
 -3.79265;5.85137;-10.49007;,
 0.63245;5.21683;-17.54147;,
 4.76850;-61.29753;-14.12207;,
 9.16105;-27.43017;-8.29652;,
 -6.04925;-76.54385;-23.22757;,
 -5.89775;-72.65324;-20.17052;,
 -7.94615;-68.93113;-23.74773;,
 -8.33995;-74.20770;-26.89447;,
 -1.51580;-76.01015;-24.15337;,
 -0.48774;-71.95184;-21.00291;,
 -5.89775;-72.65324;-20.17052;,
 -6.04925;-76.54385;-23.22757;,
 -2.84715;-67.67638;-25.29817;,
 -0.48774;-71.95184;-21.00291;,
 -1.51580;-76.01015;-24.15337;,
 -3.90339;-73.55544;-28.07573;,
 -8.33995;-74.20770;-26.89447;,
 -7.94615;-68.93113;-23.74773;,
 -2.84715;-67.67638;-25.29817;,
 -3.90339;-73.55544;-28.07573;,
 2.00460;-71.81869;-20.93033;,
 0.17730;-67.46519;-25.68773;,
 6.81475;-70.97430;-21.59807;,
 2.00460;-71.81869;-20.93033;,
 5.50840;-66.86918;-25.13933;,
 6.81475;-70.97430;-21.59807;,
 0.17730;-67.46519;-25.68773;,
 5.50840;-66.86918;-25.13933;,
 -4.01620;-83.97305;-25.25452;,
 -5.61934;-84.58096;-28.25587;,
 -6.71565;-83.91700;-24.55727;,
 -4.01620;-83.97305;-25.25452;,
 -8.30660;-84.53660;-27.49492;,
 -6.71565;-83.91700;-24.55727;,
 -5.61934;-84.58096;-28.25587;,
 -8.30660;-84.53660;-27.49492;,
 5.23415;1.85102;-9.61197;,
 3.09375;-2.06367;12.39902;,
 4.37165;-10.54988;8.29178;,
 7.42360;-7.29252;-10.56232;,
 7.80770;-20.28352;3.39608;,
 9.79920;-16.69163;-12.48647;,
 2.38625;2.05132;-0.12287;;
 
 77;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,0,3;,
 4;14,15,16,17;,
 4;18,19,20,21;,
 4;22,23,24,25;,
 4;23,14,17,24;,
 4;17,16,26,27;,
 4;21,20,28,29;,
 4;25,24,30,31;,
 4;24,17,27,30;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;40,41,42,43;,
 4;41,44,45,42;,
 4;44,46,47,45;,
 4;46,40,43,47;,
 4;33,48,49,50;,
 4;48,51,52,49;,
 4;41,40,53,54;,
 4;34,33,50,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;72,75,51,76;,
 4;77,78,5,4;,
 4;0,13,79,80;,
 4;80,81,1,0;,
 4;20,25,31,28;,
 4;19,22,25,20;,
 4;6,5,13,12;,
 4;79,13,5,78;,
 4;16,15,18,21;,
 4;26,16,21,29;,
 4;74,73,35,34;,
 4;33,32,82,48;,
 4;82,76,51,48;,
 4;12,3,23,22;,
 4;3,2,14,23;,
 4;2,83,15,14;,
 4;18,15,83,7;,
 4;7,6,19,18;,
 4;6,12,22,19;,
 4;27,26,82,32;,
 4;35,30,27,32;,
 4;31,30,35,73;,
 4;72,28,31,73;,
 4;76,29,28,72;,
 4;82,26,29,76;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;64,100,101,65;,
 4;60,102,103,61;,
 4;104,105,57,56;,
 4;68,106,107,69;,
 4;95,94,108,109;,
 4;88,91,110,111;,
 4;84,87,112,113;,
 4;96,99,114,115;,
 4;116,117,118,119;,
 4;119,118,120,121;,
 3;78,77,79;,
 3;83,2,7;,
 3;117,116,122;,
 3;81,80,79;,
 4;81,116,119,1;,
 4;4,118,117,77;,
 4;1,119,121,2;,
 4;2,121,120,7;,
 4;7,120,118,4;,
 4;77,117,122,79;,
 4;79,122,116,81;;
 
 MeshMaterialList {
  11;
  77;
  1,
  1,
  7,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  7,
  3,
  3,
  3,
  3,
  1,
  1,
  3,
  1,
  7,
  7,
  7,
  7,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  7,
  7,
  7,
  7,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\他の作品\\チーム\\-s_0.2_0.2_dinosaur-skin0.png";
   }
  }
  Material {
   0.442400;0.442400;0.442400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.276500;0.276500;0.276500;;
   TextureFilename {
    "dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.448800;0.448800;0.448800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.280500;0.280500;0.280500;;
   TextureFilename {
    "dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.564800;0.564800;0.564800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.353000;0.353000;0.353000;;
   TextureFilename {
    "dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.552000;0.552000;0.552000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.345000;0.345000;0.345000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\他の作品\\チーム\\-s_0.2_0.2_dinosaur-skin3.png";
   }
  }
  Material {
   0.800000;0.784000;0.772000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.600000;0.588000;0.579000;;
   TextureFilename {
    "Eye.png";
   }
  }
  Material {
   0.455200;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.784000;0.674400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.490000;0.421500;;
  }
  Material {
   0.649600;0.649600;0.649600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.406000;0.406000;0.406000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\他の作品\\チーム\\-s_0.333333_1_dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\他の作品\\チーム\\-s_0.333333_1_dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\他の作品\\チーム\\-s_0.333333_1_dinosaur-skin-texture-600w-256919422.png";
   }
  }
 }
 MeshNormals {
  107;
  -0.906904;-0.022722;-0.420725;,
  -0.834342;0.049790;-0.548993;,
  -0.615884;0.062302;-0.785370;,
  -0.432224;-0.053101;-0.900201;,
  -0.701672;-0.021504;-0.712176;,
  -0.983559;-0.099095;0.150968;,
  -0.916108;-0.094390;0.389663;,
  0.032014;-0.982069;0.185785;,
  -0.989810;0.006977;-0.142224;,
  -0.963882;0.035225;-0.263991;,
  -0.981189;0.046143;-0.187453;,
  0.954039;-0.222260;-0.201025;,
  0.982842;-0.165123;0.082189;,
  0.962904;-0.269803;0.004706;,
  0.899661;-0.333508;-0.281748;,
  -0.271274;-0.169583;0.947445;,
  -0.085877;-0.110173;0.990195;,
  -0.953094;-0.053115;-0.297978;,
  -0.611753;-0.209121;-0.762907;,
  -0.543658;-0.243456;-0.803222;,
  -0.966952;-0.051038;-0.249797;,
  0.777510;-0.182303;-0.601866;,
  0.391248;-0.416229;0.820779;,
  -0.986654;0.017500;-0.161890;,
  0.979678;-0.200219;0.012005;,
  0.089497;-0.357928;0.929450;,
  -0.890890;0.159914;-0.425137;,
  0.102243;0.690222;-0.716338;,
  0.101893;0.718256;-0.688278;,
  -0.200070;0.722791;-0.661472;,
  -0.343833;0.653826;-0.674010;,
  0.146479;-0.974984;0.167186;,
  0.886929;-0.041682;-0.460022;,
  0.889791;0.023899;-0.455742;,
  0.185659;-0.727564;0.660441;,
  0.192570;-0.681497;0.706030;,
  -0.932056;-0.135573;0.335993;,
  -0.914997;-0.146150;0.376060;,
  0.973831;0.226047;-0.023552;,
  0.976525;0.158630;-0.145727;,
  0.217714;-0.592174;0.775842;,
  -0.950882;-0.296665;0.088393;,
  -0.965104;-0.243365;0.096687;,
  -0.945589;-0.194884;0.260541;,
  -0.998996;-0.035684;0.027092;,
  0.455622;-0.612502;0.645948;,
  0.985483;-0.130273;0.108872;,
  -0.995859;-0.071148;0.056598;,
  -0.746490;-0.013533;-0.665259;,
  -0.949784;-0.182395;0.254249;,
  -0.878304;-0.250593;0.407167;,
  -0.597252;-0.228382;0.768851;,
  0.993666;0.080913;0.077981;,
  -0.889440;-0.117277;0.441749;,
  0.227429;-0.419930;0.878598;,
  0.872320;-0.030341;-0.487993;,
  0.113495;-0.372077;0.921237;,
  0.982196;0.078820;-0.170524;,
  0.961660;0.243510;-0.126147;,
  0.832281;0.554130;0.015773;,
  0.895325;0.018883;0.445013;,
  0.818903;0.444358;0.363241;,
  0.992643;0.106807;-0.057031;,
  0.939176;-0.038421;0.341281;,
  0.522065;0.830813;0.192870;,
  -0.277486;-0.300589;-0.912495;,
  -0.030967;-0.374790;-0.926592;,
  0.103147;-0.386404;-0.916544;,
  0.295872;-0.664376;0.686341;,
  -0.485178;0.660343;-0.573193;,
  -0.361385;0.579554;-0.730423;,
  0.402063;-0.589278;0.700783;,
  -0.958366;-0.263890;0.109076;,
  0.016823;0.615830;-0.787699;,
  0.983993;-0.013792;-0.177673;,
  0.062543;-0.180292;0.981623;,
  -0.979880;-0.155631;0.124959;,
  -0.061892;0.284958;-0.956540;,
  -0.067154;0.025706;-0.997411;,
  0.180607;-0.689014;0.701884;,
  -0.997335;-0.058291;-0.043879;,
  -0.985029;-0.126518;0.117098;,
  -0.997268;-0.014392;-0.072459;,
  0.929207;-0.094403;0.357299;,
  0.939025;-0.181274;0.292184;,
  0.937237;-0.270400;0.220160;,
  -0.573613;0.642978;-0.507491;,
  0.945729;0.314584;-0.081448;,
  0.522340;-0.535399;0.663709;,
  0.985044;-0.026841;-0.170198;,
  0.907130;-0.149849;0.393268;,
  0.086005;0.637765;-0.765414;,
  -0.304475;0.274443;-0.912127;,
  0.841805;-0.149570;-0.518645;,
  0.230139;-0.197034;0.953003;,
  -0.864765;-0.023923;0.501607;,
  -0.267945;0.055955;-0.961808;,
  0.218330;0.930690;0.293510;,
  0.315851;0.906534;0.280062;,
  0.324667;0.928389;0.180790;,
  -0.580326;0.806958;0.109729;,
  0.330119;0.940609;0.079222;,
  0.205688;0.977754;0.041094;,
  0.879560;0.252526;-0.403243;,
  0.869798;0.277222;-0.408166;,
  0.723204;-0.152568;0.673572;,
  0.741424;-0.198582;0.640980;;
  77;
  4;1,2,3,4;,
  4;50,5,6,51;,
  4;7,7,7,7;,
  4;9,10,1,4;,
  4;11,12,13,14;,
  4;15,15,16,16;,
  4;17,18,19,20;,
  4;18,65,66,19;,
  4;14,13,24,21;,
  4;16,16,25,22;,
  4;20,19,26,23;,
  4;19,66,21,67;,
  4;27,28,29,30;,
  4;31,31,31,31;,
  4;32,32,33,33;,
  4;68,34,35,35;,
  4;36,36,37,37;,
  4;69,29,70,70;,
  4;38,38,39,39;,
  4;71,68,40,40;,
  4;72,72,41,41;,
  4;29,28,73,73;,
  4;57,57,74,74;,
  4;56,56,75,75;,
  4;42,42,76,76;,
  4;77,77,78,78;,
  4;43,44,36,36;,
  4;79,34,68,45;,
  4;49,47,5,50;,
  4;1,10,8,0;,
  4;0,48,2,1;,
  4;80,20,23,81;,
  4;82,17,20,80;,
  4;6,5,10,9;,
  4;8,10,5,47;,
  4;13,12,83,84;,
  4;24,13,84,85;,
  4;69,86,30,29;,
  4;38,87,52,38;,
  4;88,45,68,71;,
  4;9,4,18,17;,
  4;4,3,65,18;,
  4;89,46,12,11;,
  4;83,12,46,90;,
  4;51,6,15,15;,
  4;6,9,17,82;,
  4;21,24,52,87;,
  4;30,91,91,27;,
  4;23,26,30,44;,
  4;43,81,23,44;,
  4;45,22,25,79;,
  4;52,24,22,45;,
  4;53,37,37,53;,
  4;54,35,35,54;,
  4;33,33,55,55;,
  4;92,70,70,92;,
  4;42,41,41,42;,
  4;56,40,40,56;,
  4;39,39,57,57;,
  4;77,73,73,77;,
  4;55,55,93,93;,
  4;54,54,94,94;,
  4;53,53,95,95;,
  4;92,92,96,96;,
  4;59,61,60,58;,
  4;58,60,63,62;,
  3;97,98,99;,
  3;100,100,100;,
  3;61,59,64;,
  3;101,102,99;,
  4;103,59,58,104;,
  4;105,60,61,106;,
  4;104,58,62,89;,
  4;89,62,63,90;,
  4;90,63,60,105;,
  4;98,61,64,99;,
  4;99,64,59,101;;
 }
 MeshTextureCoords {
  123;
  0.459917;0.521696;,
  0.445215;0.529099;,
  0.435672;0.574270;,
  0.446630;0.565191;,
  0.536180;0.544753;,
  0.507767;0.532394;,
  0.498477;0.576437;,
  0.512227;0.591533;,
  0.168780;0.197280;,
  0.142780;0.211170;,
  0.136740;0.187790;,
  0.162180;0.174010;,
  0.470883;0.567801;,
  0.480542;0.524377;,
  0.445554;0.596111;,
  0.479173;0.601310;,
  0.482695;0.621368;,
  0.458869;0.619704;,
  0.506280;0.607568;,
  0.499451;0.599229;,
  0.499271;0.618694;,
  0.500192;0.622347;,
  0.476439;0.593708;,
  0.452048;0.591375;,
  0.458474;0.617955;,
  0.480180;0.617229;,
  0.486020;0.645117;,
  0.470742;0.645158;,
  0.500638;0.645806;,
  0.498242;0.645276;,
  0.468025;0.646545;,
  0.483701;0.645222;,
  0.453146;0.666516;,
  0.441712;0.678857;,
  0.437589;0.678888;,
  0.451674;0.666757;,
  0.128480;0.177800;,
  0.130600;0.210160;,
  0.110620;0.211170;,
  0.108670;0.179480;,
  0.571477;0.704676;,
  0.555262;0.722231;,
  0.568367;0.734249;,
  0.582734;0.720330;,
  0.554206;0.724451;,
  0.566583;0.736533;,
  0.566049;0.710952;,
  0.578562;0.724415;,
  0.446028;0.691959;,
  0.438057;0.701955;,
  0.428081;0.690274;,
  0.451343;0.694232;,
  0.440315;0.704357;,
  0.583485;0.719643;,
  0.567707;0.733816;,
  0.426918;0.691970;,
  0.531800;0.900400;,
  0.573270;0.924030;,
  0.560770;0.992270;,
  0.528400;0.998050;,
  0.224390;0.148200;,
  0.189680;0.142070;,
  0.197260;0.077230;,
  0.217250;0.079970;,
  0.289270;0.140510;,
  0.329980;0.117380;,
  0.333110;0.211170;,
  0.301420;0.205360;,
  0.464030;0.904260;,
  0.498850;0.897620;,
  0.500670;0.995280;,
  0.480860;0.998050;,
  0.470915;0.680415;,
  0.462453;0.672351;,
  0.443671;0.684374;,
  0.453683;0.696172;,
  0.467460;0.677617;,
  0.556073;0.503969;,
  0.523937;0.492045;,
  0.496003;0.484193;,
  0.470444;0.483350;,
  0.450056;0.485156;,
  0.459475;0.674420;,
  0.475718;0.578051;,
  0.373240;0.928820;,
  0.346760;0.895120;,
  0.377750;0.862880;,
  0.405000;0.908590;,
  0.871630;0.572360;,
  0.880540;0.607520;,
  0.833680;0.601440;,
  0.832370;0.567740;,
  0.438430;0.064750;,
  0.475630;0.101780;,
  0.448340;0.136930;,
  0.414370;0.115670;,
  0.339250;0.121320;,
  0.342660;0.075620;,
  0.386820;0.064750;,
  0.377670;0.115670;,
  0.263970;0.109150;,
  0.305170;0.071450;,
  0.222010;0.180740;,
  0.180340;0.173430;,
  0.562780;0.855940;,
  0.593450;0.891490;,
  0.450070;0.858330;,
  0.496240;0.853170;,
  0.438810;0.205910;,
  0.412810;0.211170;,
  0.826590;0.503880;,
  0.849970;0.503390;,
  0.410200;0.998050;,
  0.384760;0.992680;,
  0.362810;0.211170;,
  0.339540;0.210790;,
  0.472269;0.494733;,
  0.535038;0.505872;,
  0.523260;0.530019;,
  0.469403;0.520751;,
  0.509079;0.557716;,
  0.463753;0.547495;,
  0.499473;0.494163;;
 }
}

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
 214;
 21.07142;-74.76391;-61.74827;,
 16.37022;-74.74801;-62.47232;,
 16.22297;-69.09696;-63.05837;,
 20.65652;-69.09016;-62.11722;,
 1.36887;3.94720;14.73508;,
 1.94332;-5.53766;21.37003;,
 7.00132;-5.79335;12.86948;,
 6.96917;4.02985;6.57293;,
 9.41122;-0.30280;-6.12152;,
 8.75962;-8.53111;-1.39292;,
 5.28662;-10.60866;-9.09332;,
 5.55232;-3.81920;-13.99342;,
 -2.56293;-12.05066;-10.18942;,
 -2.93173;-5.56456;-14.83767;,
 -7.85003;-10.65976;-3.43212;,
 -8.46248;-2.09551;-7.99207;,
 -8.41073;2.54765;7.16988;,
 -8.74313;-7.86096;12.56498;,
 -5.92923;-6.60906;20.90883;,
 -6.10673;2.97776;15.63288;,
 2.36767;-16.86406;16.22173;,
 7.73012;-18.49361;8.01398;,
 8.65442;-18.87976;-3.68557;,
 4.99107;-18.90691;-10.17107;,
 -2.51823;-19.74271;-11.00057;,
 -8.20443;-19.98701;-5.27517;,
 -9.18893;-18.89691;9.18708;,
 -5.53998;-17.11131;15.91898;,
 -4.79853;-49.12246;2.46698;,
 -8.28873;-61.38371;-5.38197;,
 0.10972;-60.28481;-1.70842;,
 1.09642;-48.17825;2.87613;,
 8.90317;-38.90471;-11.49857;,
 10.22627;-48.25540;-16.41632;,
 5.46572;-44.96336;-21.83842;,
 4.91822;-37.53441;-16.69847;,
 -2.55153;-44.91241;-22.30122;,
 -2.42068;-37.94916;-17.49557;,
 -9.11638;-46.79806;-16.63347;,
 -8.26993;-38.41716;-12.35082;,
 -9.96713;-45.01481;-1.69207;,
 -11.32988;-40.94466;-6.84057;,
 -14.00083;-51.07620;-11.23232;,
 -13.65298;-55.29845;-2.49517;,
 15.85842;-72.50837;-34.36867;,
 15.90472;-62.67326;-36.64747;,
 8.95102;-71.03326;-18.15867;,
 5.61057;-60.18391;-41.18207;,
 -4.54493;-59.79481;-41.07632;,
 -14.38318;-61.07095;-36.38822;,
 -14.79563;-71.11866;-33.67667;,
 -12.47863;-67.78811;-19.81667;,
 0.63742;-73.02566;-17.67147;,
 5.46302;-73.26661;-36.75122;,
 -13.79433;-73.62942;-61.74697;,
 -17.98333;-73.53442;-60.79712;,
 -17.65413;-68.20296;-61.16582;,
 -13.59678;-68.26637;-62.37447;,
 4.07392;-74.21331;-65.63872;,
 -1.67613;-73.94677;-65.53192;,
 -1.47008;-68.79671;-66.16147;,
 4.02947;-68.54430;-66.25047;,
 20.55037;-74.22121;-43.71317;,
 19.32782;-62.38511;-46.16612;,
 15.90472;-62.67326;-36.64747;,
 15.85842;-72.50837;-34.36867;,
 5.61057;-60.18391;-41.18207;,
 15.90472;-62.67326;-36.64747;,
 19.32782;-62.38511;-46.16612;,
 9.08387;-61.84181;-49.28407;,
 5.61057;-60.18391;-41.18207;,
 9.08387;-61.84181;-49.28407;,
 9.77207;-73.93487;-45.60547;,
 5.46302;-73.26661;-36.75122;,
 5.46302;-73.26661;-36.75122;,
 9.77207;-73.93487;-45.60547;,
 20.55037;-74.22121;-43.71317;,
 15.85842;-72.50837;-34.36867;,
 -4.81883;-72.61187;-36.40747;,
 -8.59223;-73.45127;-45.23097;,
 -8.61948;-62.29796;-48.56987;,
 -4.54493;-59.79481;-41.07632;,
 -4.54493;-59.79481;-41.07632;,
 -8.61948;-62.29796;-48.56987;,
 -16.67998;-62.45531;-45.46752;,
 -14.38318;-61.07095;-36.38822;,
 -16.67998;-62.45531;-45.46752;,
 -17.16998;-73.38456;-43.17732;,
 -14.79563;-71.11866;-33.67667;,
 -17.16998;-73.38456;-43.17732;,
 -8.59223;-73.45127;-45.23097;,
 -4.81883;-72.61187;-36.40747;,
 6.71332;-73.59481;-46.30517;,
 6.15577;-61.95116;-49.52867;,
 5.61057;-60.18391;-41.18207;,
 6.15577;-61.95116;-49.52867;,
 -5.12578;-62.24191;-49.27727;,
 -4.54493;-59.79481;-41.07632;,
 -5.12578;-62.24191;-49.27727;,
 -5.30798;-73.25681;-46.04132;,
 -4.81883;-72.61187;-36.40747;,
 -5.30798;-73.25681;-46.04132;,
 6.71332;-73.59481;-46.30517;,
 21.38052;-74.13467;-54.47517;,
 20.46342;-63.91920;-55.32917;,
 20.46342;-63.91920;-55.32917;,
 12.60852;-63.87721;-57.23302;,
 12.60852;-63.87721;-57.23302;,
 12.85637;-74.06672;-55.72162;,
 12.85637;-74.06672;-55.72162;,
 21.38052;-74.13467;-54.47517;,
 -10.74293;-73.20422;-55.11578;,
 -10.55203;-63.05006;-56.80322;,
 -10.55203;-63.05006;-56.80322;,
 -18.10538;-62.99821;-54.29167;,
 -16.67998;-62.45531;-45.46752;,
 -18.10538;-62.99821;-54.29167;,
 -18.70618;-73.03727;-53.39437;,
 -17.16998;-73.38456;-43.17732;,
 -18.70618;-73.03727;-53.39437;,
 -10.74293;-73.20422;-55.11578;,
 6.71332;-73.59481;-46.30517;,
 6.27637;-73.15421;-57.50212;,
 6.02467;-63.35786;-58.91797;,
 6.15577;-61.95116;-49.52867;,
 6.02467;-63.35786;-58.91797;,
 -4.13838;-63.34676;-58.72652;,
 -4.13838;-63.34676;-58.72652;,
 -4.45403;-72.73336;-57.29192;,
 -4.45403;-72.73336;-57.29192;,
 6.27637;-73.15421;-57.50212;,
 20.65652;-69.09016;-62.11722;,
 21.07142;-74.76391;-61.74827;,
 20.65652;-69.09016;-62.11722;,
 16.22297;-69.09696;-63.05837;,
 16.22297;-69.09696;-63.05837;,
 16.37022;-74.74801;-62.47232;,
 16.37022;-74.74801;-62.47232;,
 21.07142;-74.76391;-61.74827;,
 -13.79433;-73.62942;-61.74697;,
 -13.59678;-68.26637;-62.37447;,
 -13.59678;-68.26637;-62.37447;,
 -17.65413;-68.20296;-61.16582;,
 -17.65413;-68.20296;-61.16582;,
 -17.98333;-73.53442;-60.79712;,
 -17.98333;-73.53442;-60.79712;,
 -13.79433;-73.62942;-61.74697;,
 4.07392;-74.21331;-65.63872;,
 4.02947;-68.54430;-66.25047;,
 4.02947;-68.54430;-66.25047;,
 -1.47008;-68.79671;-66.16147;,
 -1.47008;-68.79671;-66.16147;,
 -1.67613;-73.94677;-65.53192;,
 -1.67613;-73.94677;-65.53192;,
 4.07392;-74.21331;-65.63872;,
 -4.81883;-72.61187;-36.40747;,
 -6.17848;-71.87731;-18.50872;,
 -12.43738;-62.72816;-5.99932;,
 -14.81408;-62.11936;-5.59337;,
 -15.00588;-60.21361;-9.26572;,
 -12.91883;-61.22591;-9.04947;,
 -8.28873;-61.38371;-5.38197;,
 -11.09298;-58.81981;-10.47112;,
 -11.09298;-58.81981;-10.47112;,
 -12.91883;-61.22591;-9.04947;,
 -15.00588;-60.21361;-9.26572;,
 -14.00083;-51.07620;-11.23232;,
 -14.00083;-51.07620;-11.23232;,
 -15.00588;-60.21361;-9.26572;,
 -14.81408;-62.11936;-5.59337;,
 -13.65298;-55.29845;-2.49517;,
 -13.65298;-55.29845;-2.49517;,
 -14.81408;-62.11936;-5.59337;,
 -12.43738;-62.72816;-5.99932;,
 -8.28873;-61.38371;-5.38197;,
 10.36097;-40.78846;-5.72862;,
 11.36392;-51.57561;-10.26002;,
 9.90527;-6.87736;4.71253;,
 10.13142;-18.85781;1.55243;,
 10.80132;2.42250;-0.10217;,
 -10.41518;-9.18101;3.75188;,
 -10.77523;0.07621;-0.22282;,
 -11.22353;-20.24676;0.81178;,
 8.65442;-18.87976;-3.68557;,
 8.90317;-38.90471;-11.49857;,
 4.91822;-37.53441;-16.69847;,
 4.99107;-18.90691;-10.17107;,
 10.13142;-18.85781;1.55243;,
 10.36097;-40.78846;-5.72862;,
 7.69772;-43.27651;-1.56612;,
 7.73012;-18.49361;8.01398;,
 2.36767;-16.86406;16.22173;,
 1.09642;-48.17825;2.87613;,
 -5.53998;-17.11131;15.91898;,
 -4.79853;-49.12246;2.46698;,
 -8.26993;-38.41716;-12.35082;,
 -11.32988;-40.94466;-6.84057;,
 -11.22353;-20.24676;0.81178;,
 -8.20443;-19.98701;-5.27517;,
 -2.51823;-19.74271;-11.00057;,
 -2.42068;-37.94916;-17.49557;,
 -11.09298;-58.81981;-10.47112;,
 8.40007;-58.67490;-3.55597;,
 7.69772;-43.27651;-1.56612;,
 7.51257;3.12081;-0.15747;,
 6.52737;1.18925;-4.42357;,
 4.79662;4.25995;4.57343;,
 3.79247;-1.30290;-10.00262;,
 0.82747;4.20141;10.35823;,
 -2.22048;-2.53991;-10.60097;,
 -4.47073;3.51430;10.99453;,
 -6.14033;-0.08129;-5.74927;,
 -6.10363;3.20951;4.99653;,
 -7.77943;1.45791;-0.24297;;
 
 115;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;16,17,18,19;,
 4;19,18,5,4;,
 4;5,20,21,6;,
 4;9,22,23,10;,
 4;10,23,24,12;,
 4;12,24,25,14;,
 4;17,26,27,18;,
 4;18,27,20,5;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;35,34,36,37;,
 4;37,36,38,39;,
 4;40,41,42,43;,
 4;44,45,33,46;,
 4;34,33,45,47;,
 4;34,47,48,36;,
 4;36,48,49,38;,
 4;38,49,50,51;,
 4;52,53,44,46;,
 4;54,55,56,57;,
 4;58,59,60,61;,
 4;62,63,64,65;,
 4;66,67,68,69;,
 4;70,71,72,73;,
 4;74,75,76,77;,
 4;78,79,80,81;,
 4;82,83,84,85;,
 4;49,86,87,50;,
 4;88,89,90,91;,
 4;53,92,93,47;,
 4;94,95,96,82;,
 4;97,98,99,100;,
 4;91,101,102,74;,
 4;103,104,63,62;,
 4;69,68,105,106;,
 4;71,107,108,72;,
 4;75,109,110,76;,
 4;79,111,112,80;,
 4;83,113,114,84;,
 4;115,116,117,118;,
 4;89,119,120,90;,
 4;121,122,123,124;,
 4;95,125,126,96;,
 4;98,127,128,99;,
 4;101,129,130,102;,
 4;131,104,103,132;,
 4;106,105,133,134;,
 4;107,135,136,108;,
 4;109,137,138,110;,
 4;111,139,140,112;,
 4;113,141,142,114;,
 4;116,143,144,117;,
 4;119,145,146,120;,
 4;122,147,148,123;,
 4;125,149,150,126;,
 4;127,151,152,128;,
 4;129,153,154,130;,
 4;51,50,155,156;,
 4;156,155,53,52;,
 4;157,158,159,160;,
 4;161,157,160,162;,
 4;163,164,165,166;,
 4;167,168,169,170;,
 4;171,172,173,174;,
 4;175,176,33,32;,
 4;177,178,22,9;,
 4;179,177,9,8;,
 4;6,177,179,7;,
 4;21,178,177,6;,
 4;14,180,181,15;,
 4;25,182,180,14;,
 4;38,42,41,39;,
 4;180,182,26,17;,
 4;181,180,17,16;,
 4;183,184,185,186;,
 4;187,188,184,183;,
 4;189,188,187,190;,
 4;191,192,189,190;,
 4;193,194,192,191;,
 4;26,40,28,27;,
 4;182,41,40,26;,
 4;195,196,197,198;,
 4;199,200,195,198;,
 4;23,35,37,24;,
 4;51,201,42,38;,
 4;202,176,175,203;,
 4;43,29,28,40;,
 4;33,176,202,46;,
 4;30,52,46,202;,
 4;29,156,52,30;,
 4;51,156,29,201;,
 4;31,30,202,203;,
 3;204,205,206;,
 3;205,207,206;,
 3;206,207,208;,
 3;207,209,208;,
 3;208,209,210;,
 3;209,211,210;,
 3;210,211,212;,
 3;211,213,212;,
 4;4,7,206,208;,
 4;7,179,204,206;,
 4;179,8,205,204;,
 4;8,11,207,205;,
 4;11,13,209,207;,
 4;13,15,211,209;,
 4;15,181,213,211;,
 4;181,16,212,213;,
 4;16,19,210,212;,
 4;19,4,208,210;;
 
 MeshMaterialList {
  11;
  115;
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
  7,
  7,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  1,
  1,
  7,
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
  3,
  3,
  3,
  3,
  3,
  1,
  1,
  3,
  3,
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
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\���̍�i\\�`�[��\\-s_0.2_0.2_dinosaur-skin0.png";
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
    "C:\\Users\\student\\Desktop\\���̍�i\\�`�[��\\-s_0.2_0.2_dinosaur-skin3.png";
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
    "C:\\Users\\student\\Desktop\\���̍�i\\�`�[��\\-s_0.333333_1_dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\���̍�i\\�`�[��\\-s_0.333333_1_dinosaur-skin-texture-600w-256919422.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;
   TextureFilename {
    "C:\\Users\\student\\Desktop\\���̍�i\\�`�[��\\-s_0.333333_1_dinosaur-skin-texture-600w-256919422.png";
   }
  }
 }
 MeshNormals {
  145;
  0.180153;0.403203;-0.897202;,
  0.206297;0.871049;0.445774;,
  0.852941;0.270861;0.446236;,
  0.887889;0.071430;0.454478;,
  0.485662;0.087978;0.869708;,
  0.946412;-0.217325;-0.238902;,
  0.621086;-0.467638;-0.628941;,
  0.620546;-0.195626;-0.759377;,
  0.951108;-0.079264;-0.298514;,
  0.206254;-0.569835;-0.795454;,
  0.167411;-0.243952;-0.955228;,
  -0.880815;-0.272137;-0.387436;,
  -0.877034;-0.073477;-0.474775;,
  -0.960123;0.127017;0.249057;,
  -0.949390;0.153337;0.274128;,
  -0.935802;-0.001923;0.352522;,
  -0.958058;0.023245;0.285629;,
  0.856690;-0.170445;0.486857;,
  0.425900;-0.352491;0.833282;,
  0.922949;0.105031;-0.370316;,
  -0.340318;0.226246;-0.912687;,
  -0.813532;0.171401;-0.555687;,
  -0.840066;-0.200813;0.503947;,
  -0.922393;-0.121330;0.366702;,
  -0.348786;-0.329363;0.877421;,
  0.269404;-0.349174;0.897496;,
  0.093762;-0.581621;0.808038;,
  0.909565;0.216963;-0.354428;,
  0.486467;0.411046;-0.770967;,
  0.398262;0.659973;-0.637043;,
  0.955821;0.251796;-0.151672;,
  -0.321512;0.429898;-0.843693;,
  -0.778481;0.301052;-0.550759;,
  -0.836626;-0.083640;0.541351;,
  -0.967948;0.168971;0.185810;,
  -0.980904;0.172630;-0.089590;,
  0.994276;-0.004876;0.106729;,
  0.861229;-0.152918;0.484665;,
  -0.271024;0.675917;-0.685334;,
  -0.850931;0.341922;-0.398756;,
  0.926335;0.067547;0.370595;,
  0.981469;-0.061407;0.181516;,
  0.206971;0.914706;-0.347097;,
  -0.149088;0.905404;-0.397513;,
  -0.312338;0.887639;-0.338440;,
  -0.978705;-0.194900;0.064428;,
  -0.976524;0.100591;0.190480;,
  0.024038;-0.934909;0.354072;,
  -0.005095;-0.997492;0.070596;,
  -0.246506;0.390275;-0.887085;,
  -0.017587;-0.113867;-0.993340;,
  0.962764;0.120984;0.241761;,
  0.117122;0.988109;-0.099610;,
  -0.921686;-0.129472;-0.365693;,
  0.943584;-0.101393;-0.315228;,
  -0.089682;0.987945;-0.126183;,
  -0.978298;0.084904;0.189011;,
  0.998748;0.038862;0.031501;,
  -0.006541;0.981467;-0.191520;,
  -0.999606;0.021191;-0.018396;,
  0.995343;0.093224;0.024521;,
  0.111473;0.908676;-0.402346;,
  -0.911583;-0.095755;-0.399808;,
  0.945484;-0.071537;-0.317714;,
  -0.112711;0.927154;-0.357325;,
  -0.997633;0.063819;0.025600;,
  0.989684;0.007123;-0.143088;,
  -0.022452;0.929483;-0.368182;,
  -0.978067;-0.001946;-0.208280;,
  0.179448;-0.074380;-0.980952;,
  -0.253940;-0.077373;-0.964120;,
  -0.369441;-0.868795;0.329710;,
  0.901651;-0.143058;-0.408117;,
  0.034247;-0.866806;-0.497467;,
  -0.042155;-0.718532;-0.694215;,
  -0.272952;-0.633696;-0.723828;,
  -0.326445;-0.856236;-0.400366;,
  0.117307;-0.586655;-0.801296;,
  -0.299451;-0.505917;0.808936;,
  0.991920;0.017461;0.125657;,
  0.995722;-0.000541;0.092395;,
  0.997145;-0.015773;0.073843;,
  0.991863;0.006904;0.127124;,
  -0.998927;-0.040673;-0.022128;,
  -0.998051;0.015491;-0.060443;,
  -0.992800;0.060850;-0.103180;,
  0.534703;0.198349;-0.821432;,
  0.770319;-0.182753;0.610909;,
  -0.979529;0.159319;-0.123046;,
  -0.115522;0.968632;-0.220015;,
  -0.169782;0.973873;-0.150817;,
  0.056328;0.947905;-0.313534;,
  -0.004344;0.911699;-0.410835;,
  -0.142009;0.904921;-0.401187;,
  -0.063904;0.917247;-0.393159;,
  0.069833;0.930215;-0.360311;,
  -0.301990;0.912752;-0.275110;,
  -0.023353;0.982804;-0.183168;,
  0.094857;0.985850;-0.138212;,
  -0.789790;-0.358124;-0.497975;,
  -0.788829;-0.127281;-0.601289;,
  -0.157383;0.923437;0.349992;,
  -0.031453;0.060251;0.997688;,
  -0.010773;-0.405602;0.913986;,
  0.393330;0.890203;-0.229849;,
  0.070539;-0.991473;0.109572;,
  0.205135;-0.905075;0.372504;,
  -0.907400;-0.148088;-0.393314;,
  -0.009426;-0.997994;0.062601;,
  -0.201241;-0.963991;0.173846;,
  -0.026228;-0.996586;0.078282;,
  -0.141113;-0.984675;0.102484;,
  0.994787;0.047283;0.090354;,
  -0.997858;0.036550;0.054257;,
  -0.039434;-0.999216;0.003536;,
  -0.017989;-0.998905;0.043183;,
  -0.013627;-0.999694;0.020662;,
  -0.037280;-0.998194;0.047114;,
  0.996032;0.077989;-0.042883;,
  -0.884184;-0.080381;-0.460172;,
  -0.018891;-0.995922;0.088218;,
  0.906653;-0.083801;-0.413470;,
  -0.993414;0.052302;-0.101947;,
  -0.006963;-0.997738;0.066862;,
  0.966354;-0.016156;-0.256708;,
  -0.028610;0.813332;-0.581097;,
  -0.946464;-0.009579;-0.322667;,
  -0.039734;-0.989768;0.137044;,
  -0.364718;-0.917034;0.161335;,
  0.390157;-0.756336;-0.525103;,
  -0.176601;-0.311656;-0.933639;,
  -0.986497;0.123745;0.107289;,
  -0.174968;-0.321765;0.930513;,
  0.025388;-0.423038;0.905756;,
  -0.896286;-0.076548;-0.436821;,
  0.249507;-0.743798;0.620090;,
  -0.707329;-0.544042;0.451336;,
  0.134449;0.990400;-0.032098;,
  0.203801;0.937513;-0.282019;,
  0.182211;0.871116;-0.456022;,
  0.029799;0.851393;-0.523681;,
  -0.142581;0.816723;-0.559137;,
  -0.286539;0.841114;-0.458718;,
  -0.405658;0.875735;-0.261784;,
  -0.338379;0.938134;-0.073514;;
  115;
  4;69,69,0,0;,
  4;1,4,3,2;,
  4;5,8,7,6;,
  4;6,7,10,9;,
  4;99,100,12,11;,
  4;13,16,15,14;,
  4;101,102,4,1;,
  4;4,18,17,3;,
  4;8,19,86,7;,
  4;7,86,20,10;,
  4;100,20,21,12;,
  4;16,23,22,15;,
  4;102,103,18,4;,
  4;24,78,26,25;,
  4;27,30,29,28;,
  4;28,29,38,31;,
  4;31,38,39,32;,
  4;33,35,88,34;,
  4;40,40,30,41;,
  4;29,30,104,42;,
  4;29,42,43,38;,
  4;38,43,44,39;,
  4;39,46,46,45;,
  4;47,48,105,106;,
  4;70,70,49,49;,
  4;50,50,50,50;,
  4;51,51,40,40;,
  4;42,104,52,52;,
  4;107,53,53,107;,
  4;48,108,108,105;,
  4;72,54,54,72;,
  4;43,55,55,44;,
  4;46,56,56,46;,
  4;109,110,110,111;,
  4;112,57,57,112;,
  4;42,58,58,43;,
  4;113,59,59,113;,
  4;111,114,114,48;,
  4;60,60,51,51;,
  4;52,52,61,61;,
  4;53,62,62,53;,
  4;108,115,115,108;,
  4;54,63,63,54;,
  4;55,64,64,55;,
  4;56,65,65,56;,
  4;110,116,116,110;,
  4;57,66,66,57;,
  4;58,67,67,58;,
  4;59,68,68,59;,
  4;114,117,117,114;,
  4;118,60,60,118;,
  4;61,61,0,0;,
  4;62,119,119,62;,
  4;115,120,120,115;,
  4;63,121,121,63;,
  4;64,49,49,64;,
  4;65,122,122,65;,
  4;116,123,123,116;,
  4;66,124,124,66;,
  4;67,125,125,67;,
  4;68,126,126,68;,
  4;117,127,127,117;,
  4;128,109,111,71;,
  4;71,111,48,47;,
  4;73,76,75,74;,
  4;129,73,74,77;,
  4;77,74,75,130;,
  4;88,131,131,34;,
  4;132,133,133,78;,
  4;79,36,30,27;,
  4;80,81,19,8;,
  4;82,80,8,5;,
  4;3,80,82,2;,
  4;17,81,80,3;,
  4;12,84,83,11;,
  4;21,85,84,12;,
  4;39,88,35,32;,
  4;84,85,23,16;,
  4;83,84,16,13;,
  4;19,27,28,86;,
  4;81,79,27,19;,
  4;87,79,81,17;,
  4;18,25,87,17;,
  4;103,24,25,18;,
  4;23,33,24,22;,
  4;85,35,33,23;,
  4;32,35,85,21;,
  4;20,31,32,21;,
  4;86,28,31,20;,
  4;45,134,88,39;,
  4;37,36,79,87;,
  4;132,78,24,33;,
  4;30,36,37,41;,
  4;26,47,106,135;,
  4;78,71,47,26;,
  4;45,71,78,136;,
  4;25,26,37,87;,
  3;91,92,89;,
  3;92,93,89;,
  3;89,93,90;,
  3;93,94,90;,
  3;90,94,98;,
  3;94,95,98;,
  3;98,95,97;,
  3;95,96,97;,
  4;1,137,89,90;,
  4;137,138,91,89;,
  4;138,139,92,91;,
  4;139,140,93,92;,
  4;140,141,94,93;,
  4;141,142,95,94;,
  4;142,143,96,95;,
  4;143,144,97,96;,
  4;144,101,98,97;,
  4;101,1,90,98;;
 }
 MeshTextureCoords {
  214;
  0.289820;0.179840;,
  0.307100;0.179780;,
  0.307640;0.159010;,
  0.291350;0.158980;,
  0.541812;0.488768;,
  0.560642;0.515757;,
  0.536086;0.516485;,
  0.518178;0.488533;,
  0.481886;0.500862;,
  0.495385;0.524275;,
  0.473740;0.530187;,
  0.459782;0.510867;,
  0.471207;0.534290;,
  0.458013;0.515834;,
  0.490822;0.530332;,
  0.477897;0.505963;,
  0.521021;0.492751;,
  0.536392;0.522368;,
  0.559916;0.518806;,
  0.544922;0.491527;,
  0.545966;0.547986;,
  0.522220;0.552623;,
  0.488872;0.553722;,
  0.470697;0.553799;,
  0.468897;0.556177;,
  0.485606;0.556872;,
  0.526817;0.553770;,
  0.545694;0.548690;,
  0.507375;0.639776;,
  0.485308;0.674665;,
  0.495132;0.671538;,
  0.508099;0.637089;,
  0.466629;0.610702;,
  0.452542;0.637309;,
  0.437474;0.627941;,
  0.452135;0.606803;,
  0.436755;0.627796;,
  0.450414;0.607983;,
  0.453365;0.633162;,
  0.465484;0.609315;,
  0.495929;0.628088;,
  0.481386;0.616506;,
  0.469093;0.645335;,
  0.493919;0.657350;,
  0.401058;0.706320;,
  0.394572;0.678334;,
  0.447681;0.702122;,
  0.382440;0.671251;,
  0.383498;0.670144;,
  0.397566;0.673775;,
  0.405309;0.702365;,
  0.444561;0.692888;,
  0.449686;0.707792;,
  0.395055;0.708477;,
  0.268540;0.179840;,
  0.283930;0.179490;,
  0.282720;0.159890;,
  0.267810;0.160130;,
  0.313540;0.158700;,
  0.314510;0.179840;,
  0.333440;0.179080;,
  0.334370;0.158870;,
  0.267750;0.996010;,
  0.276770;0.952510;,
  0.241780;0.953570;,
  0.233400;0.989720;,
  0.594590;0.103950;,
  0.556760;0.087280;,
  0.544180;0.122270;,
  0.581830;0.133730;,
  0.533400;0.168070;,
  0.527310;0.138290;,
  0.482860;0.151810;,
  0.485320;0.184360;,
  0.869410;0.234210;,
  0.853570;0.201670;,
  0.813960;0.208630;,
  0.831200;0.242970;,
  0.426870;0.088920;,
  0.423790;0.121350;,
  0.464780;0.133620;,
  0.473980;0.106080;,
  0.755170;0.091830;,
  0.770150;0.119370;,
  0.799780;0.107970;,
  0.791330;0.074600;,
  0.371911;0.677714;,
  0.378462;0.708813;,
  0.943870;0.245510;,
  0.952600;0.210600;,
  0.921070;0.203050;,
  0.907200;0.235480;,
  0.367786;0.709411;,
  0.358658;0.676280;,
  0.717850;0.092220;,
  0.715840;0.122900;,
  0.757310;0.121970;,
  0.709950;0.167200;,
  0.700960;0.137050;,
  0.660480;0.148950;,
  0.662850;0.184360;,
  0.909000;0.200070;,
  0.864810;0.199100;,
  0.307310;0.995690;,
  0.310440;0.958150;,
  0.540000;0.155950;,
  0.568870;0.162940;,
  0.519830;0.109080;,
  0.482380;0.114630;,
  0.842240;0.164490;,
  0.810910;0.169070;,
  0.424700;0.157680;,
  0.462020;0.163880;,
  0.777250;0.149630;,
  0.805020;0.140400;,
  0.467110;0.957290;,
  0.434680;0.959280;,
  0.437980;0.996180;,
  0.475530;0.997460;,
  0.958240;0.173040;,
  0.928970;0.166720;,
  0.602760;0.111050;,
  0.604380;0.152200;,
  0.640380;0.157410;,
  0.645550;0.122900;,
  0.716330;0.157410;,
  0.753680;0.156700;,
  0.696900;0.102320;,
  0.662400;0.107600;,
  0.905860;0.158720;,
  0.866420;0.157940;,
  0.335390;0.977150;,
  0.334040;0.998010;,
  0.539290;0.180900;,
  0.555590;0.184360;,
  0.500640;0.087670;,
  0.479870;0.089820;,
  0.829320;0.139680;,
  0.812040;0.142340;,
  0.423130;0.182050;,
  0.442850;0.184360;,
  0.788440;0.170110;,
  0.803360;0.165670;,
  0.409420;0.978410;,
  0.410770;0.998010;,
  0.955590;0.145830;,
  0.940190;0.142340;,
  0.600490;0.182110;,
  0.621320;0.184360;,
  0.723660;0.184360;,
  0.743870;0.184030;,
  0.676870;0.075000;,
  0.657940;0.077310;,
  0.895650;0.128430;,
  0.874510;0.128040;,
  0.396798;0.706614;,
  0.447812;0.704524;,
  0.342530;0.170400;,
  0.341040;0.179130;,
  0.354540;0.179840;,
  0.353740;0.172170;,
  0.340260;0.155150;,
  0.358970;0.165460;,
  0.364860;0.170990;,
  0.371570;0.179840;,
  0.379240;0.176120;,
  0.375550;0.142530;,
  0.385130;0.143770;,
  0.392360;0.177350;,
  0.405860;0.184360;,
  0.417240;0.159290;,
  0.833540;0.394150;,
  0.837810;0.369080;,
  0.829080;0.366840;,
  0.813830;0.371780;,
  0.482933;0.616062;,
  0.469969;0.646756;,
  0.512667;0.519569;,
  0.503661;0.553659;,
  0.498905;0.493107;,
  0.511448;0.526124;,
  0.500169;0.499783;,
  0.503145;0.557611;,
  0.510508;0.561466;,
  0.535867;0.626660;,
  0.553452;0.622199;,
  0.532218;0.561554;,
  0.493226;0.561394;,
  0.516859;0.632793;,
  0.503780;0.640893;,
  0.472628;0.560209;,
  0.446857;0.554903;,
  0.490462;0.656851;,
  0.449188;0.555708;,
  0.492797;0.659925;,
  0.541564;0.625073;,
  0.524170;0.633301;,
  0.499273;0.565916;,
  0.518548;0.565071;,
  0.536194;0.564275;,
  0.557294;0.623549;,
  0.471041;0.667369;,
  0.489259;0.666957;,
  0.494972;0.623142;,
  0.498993;0.491120;,
  0.486931;0.496616;,
  0.512652;0.487878;,
  0.471265;0.503707;,
  0.529402;0.488045;,
  0.470011;0.507227;,
  0.531607;0.490000;,
  0.484104;0.500231;,
  0.514667;0.490867;,
  0.499888;0.495852;;
 }
}
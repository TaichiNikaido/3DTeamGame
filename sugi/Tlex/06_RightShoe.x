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
 207;
 -21.11140;-74.76392;-61.74826;,
 -20.69645;-69.09015;-62.11721;,
 -16.26289;-69.09695;-63.05837;,
 -16.41015;-74.74802;-62.47231;,
 -1.40880;3.94720;14.73509;,
 -7.00909;4.02986;6.57293;,
 -7.04130;-5.79337;12.86949;,
 -1.98324;-5.53767;21.37004;,
 -9.45119;-0.30281;-6.12152;,
 -5.59229;-3.81921;-13.99342;,
 -5.32660;-10.60867;-9.09332;,
 -8.79954;-8.53112;-1.39292;,
 2.89180;-5.56457;-14.83767;,
 2.52296;-12.05067;-10.18942;,
 8.42257;-2.09551;-7.99207;,
 7.81006;-10.65977;-3.43212;,
 8.37077;2.54765;7.16988;,
 6.06676;2.97775;15.63288;,
 5.88926;-6.60907;20.90884;,
 8.70321;-7.86097;12.56498;,
 -7.77005;-18.49362;8.01398;,
 -2.40764;-16.86407;16.22173;,
 -5.03100;-18.90692;-10.17107;,
 -8.69434;-18.87977;-3.68557;,
 2.47831;-19.74272;-11.00057;,
 8.16446;-19.98702;-5.27517;,
 5.50006;-17.11132;15.91899;,
 9.14901;-18.89692;9.18708;,
 4.75856;-49.12246;2.46698;,
 -1.13634;-48.17827;2.87613;,
 -0.14964;-60.28482;-1.70842;,
 8.24881;-61.38372;-5.38197;,
 -8.94310;-38.90472;-11.49857;,
 -4.95814;-37.53442;-16.69847;,
 -5.50570;-44.96337;-21.83842;,
 -10.26620;-48.25541;-16.41632;,
 2.38076;-37.94917;-17.49557;,
 2.51155;-44.91242;-22.30122;,
 8.22997;-38.41717;-12.35082;,
 9.07647;-46.79807;-16.63347;,
 9.92722;-45.01481;-1.69207;,
 13.61302;-55.29847;-2.49517;,
 13.96092;-51.07621;-11.23232;,
 11.28996;-40.94467;-6.84057;,
 -15.89835;-72.50836;-34.36867;,
 -8.99094;-71.03326;-18.15867;,
 -15.94469;-62.67327;-36.64747;,
 -5.65054;-60.18392;-41.18207;,
 4.50501;-59.79482;-41.07632;,
 14.34321;-61.07097;-36.38822;,
 12.43871;-67.78810;-19.81667;,
 14.75572;-71.11867;-33.67667;,
 -0.67734;-73.02567;-17.67147;,
 -5.50300;-73.26662;-36.75122;,
 13.75442;-73.62943;-61.74696;,
 13.55687;-68.26636;-62.37446;,
 17.61416;-68.20296;-61.16581;,
 17.94336;-73.53442;-60.79712;,
 -4.11390;-74.21332;-65.63872;,
 -4.06939;-68.54431;-66.25046;,
 1.43011;-68.79671;-66.16147;,
 1.63620;-73.94678;-65.53191;,
 -20.59035;-74.22122;-43.71317;,
 -19.36780;-62.38512;-46.16612;,
 -9.12385;-61.84182;-49.28407;,
 -9.81200;-73.93488;-45.60547;,
 4.77887;-72.61186;-36.40747;,
 8.57956;-62.29797;-48.56987;,
 8.55231;-73.45128;-45.23097;,
 16.64006;-62.45532;-45.46752;,
 17.13001;-73.38457;-43.17732;,
 -6.19575;-61.95117;-49.52867;,
 -6.75325;-73.59482;-46.30517;,
 5.08587;-62.24192;-49.27727;,
 5.26801;-73.25682;-46.04132;,
 -21.42049;-74.13467;-54.47516;,
 -20.59035;-74.22122;-43.71317;,
 -19.36780;-62.38512;-46.16612;,
 -20.50340;-63.91922;-55.32917;,
 -9.12385;-61.84182;-49.28407;,
 -12.64850;-63.87722;-57.23301;,
 -20.50340;-63.91922;-55.32917;,
 -19.36780;-62.38512;-46.16612;,
 -9.12385;-61.84182;-49.28407;,
 -9.81200;-73.93488;-45.60547;,
 -12.89629;-74.06673;-55.72161;,
 -12.64850;-63.87722;-57.23301;,
 -9.81200;-73.93488;-45.60547;,
 -20.59035;-74.22122;-43.71317;,
 -21.42049;-74.13467;-54.47516;,
 -12.89629;-74.06673;-55.72161;,
 8.55231;-73.45128;-45.23097;,
 8.57956;-62.29797;-48.56987;,
 10.51207;-63.05007;-56.80321;,
 10.70296;-73.20422;-55.11576;,
 8.57956;-62.29797;-48.56987;,
 16.64006;-62.45532;-45.46752;,
 18.06541;-62.99822;-54.29167;,
 10.51207;-63.05007;-56.80321;,
 16.64006;-62.45532;-45.46752;,
 17.13001;-73.38457;-43.17732;,
 18.66626;-73.03728;-53.39437;,
 18.06541;-62.99822;-54.29167;,
 17.13001;-73.38457;-43.17732;,
 8.55231;-73.45128;-45.23097;,
 10.70296;-73.20422;-55.11576;,
 18.66626;-73.03728;-53.39437;,
 -6.75325;-73.59482;-46.30517;,
 -6.19575;-61.95117;-49.52867;,
 -6.06464;-63.35787;-58.91796;,
 -6.31630;-73.15422;-57.50211;,
 -6.19575;-61.95117;-49.52867;,
 5.08587;-62.24192;-49.27727;,
 4.09846;-63.34677;-58.72651;,
 -6.06464;-63.35787;-58.91796;,
 5.08587;-62.24192;-49.27727;,
 5.26801;-73.25682;-46.04132;,
 4.41406;-72.73337;-57.29191;,
 4.09846;-63.34677;-58.72651;,
 5.26801;-73.25682;-46.04132;,
 -6.75325;-73.59482;-46.30517;,
 -6.31630;-73.15422;-57.50211;,
 4.41406;-72.73337;-57.29191;,
 -20.69645;-69.09015;-62.11721;,
 -21.11140;-74.76392;-61.74826;,
 -16.26289;-69.09695;-63.05837;,
 -20.69645;-69.09015;-62.11721;,
 -16.41015;-74.74802;-62.47231;,
 -16.26289;-69.09695;-63.05837;,
 -21.11140;-74.76392;-61.74826;,
 -16.41015;-74.74802;-62.47231;,
 13.55687;-68.26636;-62.37446;,
 13.75442;-73.62943;-61.74696;,
 17.61416;-68.20296;-61.16581;,
 13.55687;-68.26636;-62.37446;,
 17.94336;-73.53442;-60.79712;,
 17.61416;-68.20296;-61.16581;,
 13.75442;-73.62943;-61.74696;,
 17.94336;-73.53442;-60.79712;,
 -4.06939;-68.54431;-66.25046;,
 -4.11390;-74.21332;-65.63872;,
 1.43011;-68.79671;-66.16147;,
 -4.06939;-68.54431;-66.25046;,
 1.63620;-73.94678;-65.53191;,
 1.43011;-68.79671;-66.16147;,
 -4.11390;-74.21332;-65.63872;,
 1.63620;-73.94678;-65.53191;,
 6.13852;-71.87732;-18.50872;,
 12.39747;-62.72817;-5.99932;,
 12.87887;-61.22592;-9.04947;,
 14.96592;-60.21362;-9.26572;,
 14.77412;-62.11937;-5.59337;,
 8.24881;-61.38372;-5.38197;,
 11.05301;-58.81982;-10.47112;,
 11.05301;-58.81982;-10.47112;,
 13.96092;-51.07621;-11.23232;,
 14.96592;-60.21362;-9.26572;,
 12.87887;-61.22592;-9.04947;,
 13.96092;-51.07621;-11.23232;,
 13.61302;-55.29847;-2.49517;,
 14.77412;-62.11937;-5.59337;,
 14.96592;-60.21362;-9.26572;,
 13.61302;-55.29847;-2.49517;,
 8.24881;-61.38372;-5.38197;,
 12.39747;-62.72817;-5.99932;,
 14.77412;-62.11937;-5.59337;,
 -10.40095;-40.78848;-5.72862;,
 -11.40390;-51.57562;-10.26002;,
 -9.94524;-6.87737;4.71253;,
 -10.17139;-18.85782;1.55243;,
 -10.84129;2.42249;-0.10217;,
 10.73531;0.07618;-0.22282;,
 10.37526;-9.18102;3.75188;,
 11.18356;-20.24677;0.81178;,
 -8.69434;-18.87977;-3.68557;,
 -5.03100;-18.90692;-10.17107;,
 -4.95814;-37.53442;-16.69847;,
 -8.94310;-38.90472;-11.49857;,
 -10.17139;-18.85782;1.55243;,
 -10.40095;-40.78848;-5.72862;,
 -7.73765;-43.27652;-1.56612;,
 -7.77005;-18.49362;8.01398;,
 -7.73765;-43.27652;-1.56612;,
 5.50006;-17.11132;15.91899;,
 -2.40764;-16.86407;16.22173;,
 -1.13634;-48.17827;2.87613;,
 4.75856;-49.12246;2.46698;,
 9.14901;-18.89692;9.18708;,
 9.92722;-45.01481;-1.69207;,
 11.18356;-20.24677;0.81178;,
 11.28996;-40.94467;-6.84057;,
 8.22997;-38.41717;-12.35082;,
 8.16446;-19.98702;-5.27517;,
 2.47831;-19.74272;-11.00057;,
 2.38076;-37.94917;-17.49557;,
 11.05301;-58.81982;-10.47112;,
 -8.44005;-58.67492;-3.55597;,
 7.73951;1.45789;-0.24297;,
 6.10041;-0.08132;-5.74927;,
 6.06371;3.20950;4.99653;,
 2.18056;-2.53992;-10.60097;,
 4.43076;3.51429;10.99453;,
 -0.86744;4.20140;10.35823;,
 -3.83239;-1.30292;-10.00262;,
 -4.83655;4.25994;4.57343;,
 -6.56734;1.18925;-4.42357;,
 -7.55254;3.12080;-0.15747;;
 
 115;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;16,17,18,19;,
 4;17,4,7,18;,
 4;7,6,20,21;,
 4;11,10,22,23;,
 4;10,13,24,22;,
 4;13,15,25,24;,
 4;19,18,26,27;,
 4;18,7,21,26;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;33,36,37,34;,
 4;36,38,39,37;,
 4;40,41,42,43;,
 4;44,45,35,46;,
 4;34,47,46,35;,
 4;34,37,48,47;,
 4;37,39,49,48;,
 4;39,50,51,49;,
 4;52,45,44,53;,
 4;54,55,56,57;,
 4;58,59,60,61;,
 4;62,44,46,63;,
 4;47,64,63,46;,
 4;47,53,65,64;,
 4;53,44,62,65;,
 4;66,48,67,68;,
 4;48,49,69,67;,
 4;49,51,70,69;,
 4;51,66,68,70;,
 4;53,47,71,72;,
 4;47,48,73,71;,
 4;48,66,74,73;,
 4;66,53,72,74;,
 4;75,76,77,78;,
 4;79,80,81,82;,
 4;83,84,85,86;,
 4;87,88,89,90;,
 4;91,92,93,94;,
 4;95,96,97,98;,
 4;99,100,101,102;,
 4;103,104,105,106;,
 4;107,108,109,110;,
 4;111,112,113,114;,
 4;115,116,117,118;,
 4;119,120,121,122;,
 4;123,124,75,78;,
 4;80,125,126,81;,
 4;86,85,127,128;,
 4;90,89,129,130;,
 4;94,93,131,132;,
 4;98,97,133,134;,
 4;102,101,135,136;,
 4;106,105,137,138;,
 4;110,109,139,140;,
 4;114,113,141,142;,
 4;118,117,143,144;,
 4;122,121,145,146;,
 4;50,147,66,51;,
 4;147,52,53,66;,
 4;148,149,150,151;,
 4;152,153,149,148;,
 4;154,155,156,157;,
 4;158,159,160,161;,
 4;162,163,164,165;,
 4;166,32,35,167;,
 4;168,11,23,169;,
 4;170,8,11,168;,
 4;6,5,170,168;,
 4;20,6,168,169;,
 4;15,14,171,172;,
 4;25,15,172,173;,
 4;39,38,43,42;,
 4;172,19,27,173;,
 4;171,16,19,172;,
 4;174,175,176,177;,
 4;178,174,177,179;,
 4;180,181,178,179;,
 4;21,20,182,29;,
 4;183,184,185,186;,
 4;187,183,186,188;,
 4;189,187,188,190;,
 4;191,192,189,190;,
 4;193,192,191,194;,
 4;175,193,194,176;,
 4;50,39,42,195;,
 4;196,182,166,167;,
 4;41,40,28,31;,
 4;35,45,196,167;,
 4;30,196,45,52;,
 4;31,30,52,147;,
 4;50,195,31,147;,
 4;29,182,196,30;,
 3;197,198,199;,
 3;198,200,199;,
 3;199,200,201;,
 3;201,200,202;,
 3;200,203,202;,
 3;202,203,204;,
 3;203,205,204;,
 3;205,206,204;,
 4;4,202,204,5;,
 4;5,204,206,170;,
 4;170,206,205,8;,
 4;8,205,203,9;,
 4;9,203,200,12;,
 4;12,200,198,14;,
 4;14,198,197,171;,
 4;171,197,199,16;,
 4;16,199,201,17;,
 4;17,201,202,4;;
 
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
  1,
  3,
  3,
  3,
  3,
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
  -0.180153;0.403203;-0.897202;,
  -0.206294;0.871051;0.445773;,
  -0.852939;0.270863;0.446237;,
  -0.887888;0.071431;0.454480;,
  -0.485661;0.087979;0.869709;,
  -0.946412;-0.217327;-0.238902;,
  -0.621086;-0.467638;-0.628941;,
  -0.620547;-0.195628;-0.759376;,
  -0.951108;-0.079266;-0.298515;,
  -0.206253;-0.569834;-0.795455;,
  -0.167411;-0.243952;-0.955228;,
  0.880814;-0.272141;-0.387436;,
  0.877034;-0.073479;-0.474776;,
  0.960123;0.127020;0.249059;,
  0.949389;0.153340;0.274130;,
  0.935801;-0.001921;0.352524;,
  0.958058;0.023246;0.285630;,
  -0.856689;-0.170447;0.486859;,
  -0.425900;-0.352492;0.833282;,
  -0.922947;0.105031;-0.370320;,
  0.340319;0.226246;-0.912686;,
  0.813532;0.171401;-0.555687;,
  0.840065;-0.200813;0.503949;,
  0.922393;-0.121330;0.366702;,
  0.348786;-0.329364;0.877421;,
  -0.269403;-0.349174;0.897496;,
  -0.093761;-0.581621;0.808039;,
  -0.909563;0.216965;-0.354431;,
  -0.486468;0.411046;-0.770967;,
  -0.398263;0.659973;-0.637042;,
  -0.955821;0.251796;-0.151673;,
  0.321513;0.429898;-0.843693;,
  0.778480;0.301054;-0.550759;,
  0.836626;-0.083641;0.541352;,
  0.967948;0.168969;0.185812;,
  0.980903;0.172631;-0.089591;,
  -0.994276;-0.004875;0.106727;,
  -0.861229;-0.152919;0.484665;,
  0.271024;0.675917;-0.685334;,
  0.850930;0.341922;-0.398756;,
  -0.926335;0.067545;0.370596;,
  -0.981469;-0.061408;0.181515;,
  -0.206972;0.914706;-0.347096;,
  0.149088;0.905404;-0.397513;,
  0.312338;0.887639;-0.338440;,
  0.978705;-0.194900;0.064428;,
  0.976524;0.100592;0.190479;,
  -0.024037;-0.934909;0.354071;,
  0.005095;-0.997492;0.070597;,
  0.246508;0.390277;-0.887084;,
  0.017587;-0.113867;-0.993340;,
  -0.962764;0.120983;0.241762;,
  -0.117122;0.988109;-0.099610;,
  0.921687;-0.129469;-0.365693;,
  -0.943584;-0.101392;-0.315227;,
  0.089682;0.987945;-0.126183;,
  0.978298;0.084904;0.189011;,
  -0.998748;0.038858;0.031500;,
  0.006541;0.981467;-0.191520;,
  0.999606;0.021186;-0.018396;,
  -0.995343;0.093226;0.024520;,
  -0.111473;0.908676;-0.402345;,
  0.911584;-0.095752;-0.399808;,
  -0.945484;-0.071537;-0.317714;,
  0.112711;0.927155;-0.357324;,
  0.997633;0.063820;0.025597;,
  -0.989685;0.007122;-0.143087;,
  0.022451;0.929483;-0.368182;,
  0.978067;-0.001948;-0.208279;,
  -0.179447;-0.074381;-0.980952;,
  0.253943;-0.077373;-0.964119;,
  0.369441;-0.868795;0.329710;,
  -0.901650;-0.143057;-0.408119;,
  -0.034246;-0.866807;-0.497467;,
  0.042155;-0.718533;-0.694215;,
  0.272953;-0.633695;-0.723828;,
  0.326448;-0.856235;-0.400367;,
  -0.117308;-0.586657;-0.801295;,
  0.299451;-0.505917;0.808936;,
  -0.991920;0.017462;0.125656;,
  -0.995722;-0.000541;0.092393;,
  -0.997145;-0.015773;0.073841;,
  -0.991863;0.006904;0.127124;,
  0.998927;-0.040673;-0.022128;,
  0.998051;0.015490;-0.060444;,
  0.992799;0.060851;-0.103183;,
  -0.534704;0.198348;-0.821432;,
  -0.770317;-0.182753;0.610911;,
  0.979529;0.159318;-0.123045;,
  0.115525;0.968632;-0.220016;,
  0.169784;0.973872;-0.150818;,
  -0.056327;0.947905;-0.313534;,
  0.004344;0.911699;-0.410835;,
  0.142010;0.904921;-0.401187;,
  -0.023366;0.926453;-0.375684;,
  0.108915;0.916976;-0.383786;,
  0.301989;0.912753;-0.275109;,
  0.002989;0.981054;-0.193709;,
  0.005800;0.995120;-0.098500;,
  0.789789;-0.358128;-0.497974;,
  0.788829;-0.127282;-0.601288;,
  0.157385;0.923437;0.349991;,
  0.031454;0.060251;0.997688;,
  0.010772;-0.405602;0.913986;,
  -0.393331;0.890203;-0.229848;,
  -0.205135;-0.905075;0.372504;,
  -0.070540;-0.991473;0.109572;,
  0.907400;-0.148086;-0.393313;,
  0.009425;-0.997994;0.062601;,
  0.201239;-0.963992;0.173846;,
  0.141112;-0.984675;0.102484;,
  0.026227;-0.996586;0.078282;,
  -0.994787;0.047281;0.090352;,
  0.997858;0.036546;0.054257;,
  0.039435;-0.999216;0.003536;,
  0.017989;-0.998905;0.043183;,
  0.013658;-0.999696;0.020532;,
  0.037280;-0.998194;0.047114;,
  -0.996031;0.077992;-0.042886;,
  0.884184;-0.080380;-0.460171;,
  0.018891;-0.995922;0.088218;,
  -0.906651;-0.083801;-0.413475;,
  0.993413;0.052304;-0.101952;,
  0.007025;-0.997755;0.066604;,
  -0.966354;-0.016153;-0.256708;,
  0.028608;0.813332;-0.581096;,
  0.946464;-0.009578;-0.322666;,
  0.039734;-0.989768;0.137044;,
  0.364716;-0.917035;0.161335;,
  -0.390157;-0.756338;-0.525100;,
  0.176601;-0.311657;-0.933639;,
  0.986497;0.123743;0.107291;,
  0.174967;-0.321766;0.930512;,
  -0.025388;-0.423038;0.905756;,
  0.896287;-0.076551;-0.436818;,
  -0.249506;-0.743798;0.620090;,
  0.707330;-0.544041;0.451334;,
  -0.134444;0.990401;-0.032101;,
  -0.203797;0.937514;-0.282020;,
  -0.182210;0.871116;-0.456022;,
  -0.029798;0.851393;-0.523682;,
  0.142579;0.816724;-0.559136;,
  0.286536;0.841116;-0.458717;,
  0.405658;0.875735;-0.261782;,
  0.338381;0.938133;-0.073512;;
  115;
  4;69,0,0,69;,
  4;1,2,3,4;,
  4;5,6,7,8;,
  4;6,9,10,7;,
  4;99,11,12,100;,
  4;13,14,15,16;,
  4;101,1,4,102;,
  4;4,3,17,18;,
  4;8,7,86,19;,
  4;7,10,20,86;,
  4;100,12,21,20;,
  4;16,15,22,23;,
  4;102,4,18,103;,
  4;24,25,26,78;,
  4;27,28,29,30;,
  4;28,31,38,29;,
  4;31,32,39,38;,
  4;33,34,88,35;,
  4;40,41,30,40;,
  4;29,42,104,30;,
  4;29,38,43,42;,
  4;38,39,44,43;,
  4;39,45,46,46;,
  4;47,105,106,48;,
  4;70,49,49,70;,
  4;50,50,50,50;,
  4;51,40,40,51;,
  4;42,52,52,104;,
  4;107,107,53,53;,
  4;48,106,108,108;,
  4;72,72,54,54;,
  4;43,44,55,55;,
  4;46,46,56,56;,
  4;109,110,111,111;,
  4;112,112,57,57;,
  4;42,43,58,58;,
  4;113,113,59,59;,
  4;110,48,114,114;,
  4;60,51,51,60;,
  4;52,61,61,52;,
  4;53,53,62,62;,
  4;108,108,115,115;,
  4;54,54,63,63;,
  4;55,55,64,64;,
  4;56,56,65,65;,
  4;111,111,116,116;,
  4;57,57,66,66;,
  4;58,58,67,67;,
  4;59,59,68,68;,
  4;114,114,117,117;,
  4;118,118,60,60;,
  4;61,0,0,61;,
  4;62,62,119,119;,
  4;115,115,120,120;,
  4;63,63,121,121;,
  4;64,64,49,49;,
  4;65,65,122,122;,
  4;116,116,123,123;,
  4;66,66,124,124;,
  4;67,67,125,125;,
  4;68,68,126,126;,
  4;117,117,127,127;,
  4;128,71,110,109;,
  4;71,47,48,110;,
  4;73,74,75,76;,
  4;129,77,74,73;,
  4;77,130,75,74;,
  4;88,34,131,131;,
  4;132,78,133,133;,
  4;79,27,30,36;,
  4;80,8,19,81;,
  4;82,5,8,80;,
  4;3,2,82,80;,
  4;17,3,80,81;,
  4;12,11,83,84;,
  4;21,12,84,85;,
  4;39,32,35,88;,
  4;84,16,23,85;,
  4;83,13,16,84;,
  4;19,86,28,27;,
  4;81,19,27,79;,
  4;87,17,81,79;,
  4;18,17,87,25;,
  4;103,18,25,24;,
  4;23,22,24,33;,
  4;85,23,33,35;,
  4;32,21,85,35;,
  4;20,21,32,31;,
  4;86,20,31,28;,
  4;45,39,88,134;,
  4;37,87,79,36;,
  4;132,33,24,78;,
  4;30,41,37,36;,
  4;26,135,105,47;,
  4;78,26,47,71;,
  4;45,136,78,71;,
  4;25,87,37,26;,
  3;96,95,97;,
  3;95,94,97;,
  3;97,94,98;,
  3;98,94,90;,
  3;94,93,90;,
  3;90,93,89;,
  3;93,92,89;,
  3;92,91,89;,
  4;1,90,89,137;,
  4;137,89,91,138;,
  4;138,91,92,139;,
  4;139,92,93,140;,
  4;140,93,94,141;,
  4;141,94,95,142;,
  4;142,95,96,143;,
  4;143,96,97,144;,
  4;144,97,98,101;,
  4;101,98,90,1;;
 }
 MeshTextureCoords {
  207;
  0.289820;0.179840;,
  0.291350;0.158980;,
  0.307640;0.159010;,
  0.307100;0.179780;,
  0.542019;0.488768;,
  0.519219;0.488533;,
  0.537132;0.516485;,
  0.560934;0.515757;,
  0.483291;0.500862;,
  0.460612;0.510867;,
  0.474531;0.530187;,
  0.496693;0.524275;,
  0.457579;0.515834;,
  0.470828;0.534290;,
  0.476639;0.505963;,
  0.489656;0.530332;,
  0.519771;0.492751;,
  0.544016;0.491527;,
  0.559036;0.518806;,
  0.535093;0.522368;,
  0.523374;0.552623;,
  0.546322;0.547986;,
  0.471443;0.553799;,
  0.490164;0.553722;,
  0.468524;0.556177;,
  0.484387;0.556872;,
  0.544872;0.548690;,
  0.525451;0.553770;,
  0.506663;0.639776;,
  0.508266;0.637089;,
  0.495152;0.671538;,
  0.484077;0.674665;,
  0.467959;0.610702;,
  0.452871;0.606803;,
  0.438291;0.627941;,
  0.454069;0.637309;,
  0.450057;0.607983;,
  0.436377;0.627797;,
  0.464255;0.609315;,
  0.452010;0.633162;,
  0.494447;0.628088;,
  0.491889;0.657350;,
  0.467010;0.645335;,
  0.479701;0.616506;,
  0.403423;0.706320;,
  0.449018;0.702122;,
  0.396944;0.678334;,
  0.383279;0.671251;,
  0.382823;0.670144;,
  0.395426;0.673775;,
  0.442705;0.692888;,
  0.403108;0.702365;,
  0.449784;0.707792;,
  0.395872;0.708477;,
  0.268540;0.179840;,
  0.267810;0.160130;,
  0.282720;0.159890;,
  0.283930;0.179490;,
  0.313540;0.158700;,
  0.334370;0.158870;,
  0.333440;0.179080;,
  0.314510;0.179840;,
  0.377192;0.711194;,
  0.370124;0.677514;,
  0.360492;0.675968;,
  0.371007;0.710379;,
  0.396084;0.706614;,
  0.361205;0.677266;,
  0.370704;0.709003;,
  0.369429;0.677714;,
  0.375907;0.708813;,
  0.359578;0.676280;,
  0.368789;0.709411;,
  0.359453;0.677107;,
  0.368644;0.708449;,
  0.307310;0.995690;,
  0.267750;0.996010;,
  0.276770;0.952510;,
  0.310440;0.958150;,
  0.581830;0.133730;,
  0.568870;0.162940;,
  0.540000;0.155950;,
  0.544180;0.122270;,
  0.527310;0.138290;,
  0.482860;0.151810;,
  0.482380;0.114630;,
  0.519830;0.109080;,
  0.853570;0.201670;,
  0.813960;0.208630;,
  0.810910;0.169070;,
  0.842240;0.164490;,
  0.423790;0.121350;,
  0.464780;0.133620;,
  0.462020;0.163880;,
  0.424700;0.157680;,
  0.770150;0.119370;,
  0.799780;0.107970;,
  0.805020;0.140400;,
  0.777250;0.149630;,
  0.467110;0.957290;,
  0.475530;0.997460;,
  0.437980;0.996180;,
  0.434680;0.959280;,
  0.952600;0.210600;,
  0.921070;0.203050;,
  0.928970;0.166720;,
  0.958240;0.173040;,
  0.602760;0.111050;,
  0.645550;0.122900;,
  0.640380;0.157410;,
  0.604380;0.152200;,
  0.715840;0.122900;,
  0.757310;0.121970;,
  0.753680;0.156700;,
  0.716330;0.157410;,
  0.700960;0.137050;,
  0.660480;0.148950;,
  0.662400;0.107600;,
  0.696900;0.102320;,
  0.909000;0.200070;,
  0.864810;0.199100;,
  0.866420;0.157940;,
  0.905860;0.158720;,
  0.335390;0.977150;,
  0.334040;0.998010;,
  0.555590;0.184360;,
  0.539290;0.180900;,
  0.479870;0.089820;,
  0.500640;0.087670;,
  0.812040;0.142340;,
  0.829320;0.139680;,
  0.442850;0.184360;,
  0.423130;0.182050;,
  0.803360;0.165670;,
  0.788440;0.170110;,
  0.410770;0.998010;,
  0.409420;0.978410;,
  0.940190;0.142340;,
  0.955590;0.145830;,
  0.621320;0.184360;,
  0.600490;0.182110;,
  0.743870;0.184030;,
  0.723660;0.184360;,
  0.657940;0.077310;,
  0.676870;0.075000;,
  0.874510;0.128040;,
  0.895650;0.128430;,
  0.446895;0.704524;,
  0.342530;0.170400;,
  0.353740;0.172170;,
  0.354540;0.179840;,
  0.341040;0.179130;,
  0.340260;0.155150;,
  0.358970;0.165460;,
  0.364860;0.170990;,
  0.375550;0.142530;,
  0.379240;0.176120;,
  0.371570;0.179840;,
  0.385130;0.143770;,
  0.417240;0.159290;,
  0.405860;0.184360;,
  0.392360;0.177350;,
  0.833540;0.394150;,
  0.813830;0.371780;,
  0.829080;0.366840;,
  0.837810;0.369080;,
  0.484480;0.616062;,
  0.471665;0.646756;,
  0.514145;0.519569;,
  0.505174;0.553659;,
  0.500517;0.493107;,
  0.498567;0.499783;,
  0.509899;0.526124;,
  0.501476;0.557611;,
  0.513464;0.561466;,
  0.533925;0.561554;,
  0.555135;0.622199;,
  0.538908;0.626660;,
  0.496686;0.561394;,
  0.520397;0.632793;,
  0.506410;0.640893;,
  0.475269;0.560209;,
  0.496122;0.623142;,
  0.447307;0.555708;,
  0.447670;0.554903;,
  0.490843;0.656851;,
  0.491169;0.659925;,
  0.468572;0.561522;,
  0.503810;0.646552;,
  0.495455;0.565916;,
  0.520316;0.633301;,
  0.538752;0.625073;,
  0.515759;0.565071;,
  0.535343;0.564275;,
  0.556476;0.623549;,
  0.469392;0.667369;,
  0.490514;0.666957;,
  0.498732;0.495852;,
  0.483192;0.500231;,
  0.513761;0.490867;,
  0.469683;0.507227;,
  0.530944;0.490000;,
  0.529528;0.488045;,
  0.471833;0.503707;,
  0.513369;0.487879;,
  0.487906;0.496616;,
  0.500115;0.491120;;
 }
}
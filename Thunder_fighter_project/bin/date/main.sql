/*
Navicat SQLite Data Transfer

Source Server         : myDat
Source Server Version : 30808
Source Host           : :0

Target Server Type    : SQLite
Target Server Version : 30808
File Encoding         : 65001

Date: 2020-02-23 08:27:33
*/

PRAGMA foreign_keys = OFF;

-- ----------------------------
-- Table structure for tbl_enemyPlane
-- ----------------------------
DROP TABLE IF EXISTS "main"."tbl_enemyPlane";
CREATE TABLE tbl_enemyPlane
(
	enemyPlane_startX int not null,		--�л�����ʼx����
	enemyPlane_startY int not null,		--�л�����ʼy����
	enemyPlane_enemyType int not null,	--�л�����
	enemyPlane_bulletType int not null,	--�л��ӵ�����
	enemyPlane_flightPath int not null,	--�л�����·��
	enemyPlane_bloodVolume int not null,--�л�Ѫ��
	enemyPlane_integralNum int not null,--����л���õĻ���
	enemyPlane_goldNum int not null,	--����л���õĽ��
	enemyPlane_energyNum int not null	--����л���õ�����
);

-- ----------------------------
-- Records of tbl_enemyPlane
-- ----------------------------
INSERT INTO "main"."tbl_enemyPlane" VALUES (400, 140, 0, 0, 2, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (400, 220, 0, 0, 2, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (400, 300, 0, 0, 2, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (0, 140, 1, 0, 3, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (0, 220, 1, 0, 3, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (0, 300, 1, 0, 3, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (400, 100, 1, 0, 6, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (400, 165, 1, 0, 6, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (400, 230, 1, 0, 6, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (0, 100, 0, 0, 7, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (0, 165, 0, 0, 7, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (0, 230, 0, 0, 7, 1, 10, 5, 6);
INSERT INTO "main"."tbl_enemyPlane" VALUES (100, 0, 2, 1, 8, 5, 20, 8, 18);
INSERT INTO "main"."tbl_enemyPlane" VALUES (200, 0, 2, 1, 8, 5, 20, 8, 18);
INSERT INTO "main"."tbl_enemyPlane" VALUES (300, 0, 2, 1, 8, 5, 20, 8, 18);
INSERT INTO "main"."tbl_enemyPlane" VALUES (100, 0, 2, 1, 8, 5, 20, 8, 18);
INSERT INTO "main"."tbl_enemyPlane" VALUES (200, 0, 2, 1, 8, 5, 20, 8, 18);
INSERT INTO "main"."tbl_enemyPlane" VALUES (300, 0, 2, 1, 8, 5, 20, 8, 18);
INSERT INTO "main"."tbl_enemyPlane" VALUES (100, 0, 4, 2, 8, 5, 25, 12, 20);
INSERT INTO "main"."tbl_enemyPlane" VALUES (200, 0, 4, 2, 8, 5, 25, 12, 20);
INSERT INTO "main"."tbl_enemyPlane" VALUES (300, 0, 4, 2, 8, 5, 25, 12, 20);
INSERT INTO "main"."tbl_enemyPlane" VALUES (100, 0, 5, 5, 8, 8, 36, 18, 26);
INSERT INTO "main"."tbl_enemyPlane" VALUES (200, 0, 5, 5, 8, 8, 36, 18, 26);
INSERT INTO "main"."tbl_enemyPlane" VALUES (300, 0, 5, 5, 8, 8, 36, 18, 26);
INSERT INTO "main"."tbl_enemyPlane" VALUES (450, 100, 8, 0, 10, 1, 12, 6, 8);
INSERT INTO "main"."tbl_enemyPlane" VALUES (450, 150, 8, 0, 10, 1, 12, 6, 8);
INSERT INTO "main"."tbl_enemyPlane" VALUES (450, 200, 8, 0, 10, 1, 12, 6, 8);
INSERT INTO "main"."tbl_enemyPlane" VALUES (-500, 100, 8, 0, 11, 1, 12, 6, 8);
INSERT INTO "main"."tbl_enemyPlane" VALUES (-500, 150, 8, 0, 11, 1, 12, 6, 8);
INSERT INTO "main"."tbl_enemyPlane" VALUES (-500, 200, 8, 0, 11, 1, 12, 6, 8);
INSERT INTO "main"."tbl_enemyPlane" VALUES (325, 0, 7, 0, 9, 1, 18, 12, 15);
INSERT INTO "main"."tbl_enemyPlane" VALUES (325, 0, 7, 0, 9, 1, 18, 12, 15);
INSERT INTO "main"."tbl_enemyPlane" VALUES (325, 0, 7, 0, 9, 1, 18, 12, 15);

-- ----------------------------
-- Table structure for tbl_loginTime
-- ----------------------------
DROP TABLE IF EXISTS "main"."tbl_loginTime";
CREATE TABLE tbl_loginTime
(
	user_account varchar not null,
	user_loginTime int not null
);

-- ----------------------------
-- Records of tbl_loginTime
-- ----------------------------
INSERT INTO "main"."tbl_loginTime" VALUES ('�ɰ�����', 0);
INSERT INTO "main"."tbl_loginTime" VALUES ('�������', 0);
INSERT INTO "main"."tbl_loginTime" VALUES ('admin', 0);

-- ----------------------------
-- Table structure for tbl_userGameSet
-- ----------------------------
DROP TABLE IF EXISTS "main"."tbl_userGameSet";
CREATE TABLE tbl_userGameSet
(
	user_account varchar not null,
	GameSet_headPortrait int not null,--ͷ�����ã����ݲ�ͬ��ֵȥ���ò�ͬ��ͷ��
	GameSet_pictureFrame int not null,--ͷ������ã����ݲ�ͬ��ֵȥ���ò�ͬ��ͷ���
	GameSet_mapSelcet int not null,--��ͼѡ�񣬸��ݲ�ͬ��ֵȥ���ò�ͬ�ĵ�ͼ
	GameSet_plane int not null,--�ɻ�ѡ�񣬸��ݲ�ͬ��ֵȥѡ��ͬ�ķɻ�
	GameSet_difficulty int not null,--��Ϸ�Ѷ�ѡ��0���ͼ���1�м���2�߼�
	GameSet_backgroundMusic int not null,--��Ϸ�������������С
	GameSet_soundEffectMusic int not null--��Ϸ��Ч���������С
);

-- ----------------------------
-- Records of tbl_userGameSet
-- ----------------------------
INSERT INTO "main"."tbl_userGameSet" VALUES ('�ɰ�����', 0, 0, 0, 0, 0, 49, 100);
INSERT INTO "main"."tbl_userGameSet" VALUES ('�������', 0, 0, 0, 0, 0, 49, 100);
INSERT INTO "main"."tbl_userGameSet" VALUES ('admin', 0, 0, 0, 0, 0, 49, 100);

-- ----------------------------
-- Table structure for tbl_userinfo
-- ----------------------------
DROP TABLE IF EXISTS "main"."tbl_userinfo";
CREATE TABLE tbl_userinfo
(
	user_account varchar not null,
	user_passwd varchar not null,
	user_securityQuestion varchar not null,
	user_securityAnswer varchar not null
);

-- ----------------------------
-- Records of tbl_userinfo
-- ----------------------------
INSERT INTO "main"."tbl_userinfo" VALUES ('�ɰ�����', 123456, '���ѧ���ǣ�', 'WF190501');
INSERT INTO "main"."tbl_userinfo" VALUES ('�������', 123456, '���ѧ���ǣ�', 'WF190502');
INSERT INTO "main"."tbl_userinfo" VALUES ('admin', 123456, '���ѧ���ǣ�', 'WF190526');
INSERT INTO "main"."tbl_userinfo" VALUES (123456, 123456, '����ѧ���ǣ�', 123456);

-- ----------------------------
-- Table structure for tbl_userIntegral
-- ----------------------------
DROP TABLE IF EXISTS "main"."tbl_userIntegral";
CREATE TABLE tbl_userIntegral
(
	user_account varchar not null,
	user_integral int not null
);

-- ----------------------------
-- Records of tbl_userIntegral
-- ----------------------------
INSERT INTO "main"."tbl_userIntegral" VALUES ('�ɰ�����', 9999);
INSERT INTO "main"."tbl_userIntegral" VALUES ('�������', 8888);
INSERT INTO "main"."tbl_userIntegral" VALUES ('admin', 6666);
INSERT INTO "main"."tbl_userIntegral" VALUES ('admin', 95);
INSERT INTO "main"."tbl_userIntegral" VALUES (123456, 60);
INSERT INTO "main"."tbl_userIntegral" VALUES (123456, 60);
INSERT INTO "main"."tbl_userIntegral" VALUES (123456, 50);

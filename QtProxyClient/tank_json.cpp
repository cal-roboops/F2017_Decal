#include <QJsonObject>

//typedef enum {
//    DT_M_RD = 0,
//    DT_M_LD,
//    DT_S_FL,
//    DT_S_FR,
//    DT_S_ML,
//    DT_S_MR,
//    DT_S_BL,
//    DT_S_BR
//} controls;

//QJsonObject startJ
//{
//    {controls::DT_M_RD, 0},
//    {controls::DT_M_LD, 0},
//    {controls::DT_S_FL, 0},
//    {controls::DT_S_FR, 0},
//    {controls::DT_S_ML, 0},
//    {controls::DT_S_MR, 0},
//    {controls::DT_S_BL, 0},
//    {controls::DT_S_BR, 0},
//};

QJsonObject startJ
{
    {"DT_M_RD", 0},
    {"DT_M_LD", 0},
    {"DT_S_FL", 0},
    {"DT_S_FR", 0},
    {"DT_S_ML", 0},
    {"DT_S_MR", 0},
    {"DT_S_BL", 0},
    {"DT_S_BR", 0},
};

QJsonObject zeroJ
{
    {"DT_S_FL", 0},
    {"DT_S_FR", 0},
    {"DT_S_ML", 0},
    {"DT_S_MR", 0},
    {"DT_S_BL", 0},
    {"DT_S_BR", 0},
};
QJsonObject fortyfiveJ
{
    {"DT_S_FL", 45},
    {"DT_S_FR", -45},
    {"DT_S_ML", 0},
    {"DT_S_MR", 0},
    {"DT_S_BL", 45},
    {"DT_S_BR", -45},
};
QJsonObject ninetyJ
{
    {"DT_S_FL", 90},
    {"DT_S_FR", 90},
    {"DT_S_ML", 90},
    {"DT_S_MR", 90},
    {"DT_S_BL", 90},
    {"DT_S_BR", 90},
};
QJsonObject upJ
{
    {"DT_M_RD", 1},
    {"DT_M_LD", 1},
};
QJsonObject downJ
{
    {"DT_M_RD", -1},
    {"DT_M_LD", -1},
};
QJsonObject stopJ
{
    {"DT_M_RD", 0},
    {"DT_M_LD", 0},
};

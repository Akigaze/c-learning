cmake_minimum_required(VERSION 3.16)
project(get_start C)

set(CMAKE_C_STANDARD 11)

add_executable(get_start main.c)
add_executable(helloworld helloworld/hello.c)
add_executable(escape string/escape.c)
add_executable(datatype datatype/cDataType.c)
add_executable(bitShift operation/comma.c)
add_executable(stringArray array/stringArray.c)
add_executable(functionDeclare function/functionDeclare.c function/math.c)
add_executable(localVariable variable/localVariable.c)
add_executable(macroDefine macro/macroDefine.c)
add_executable(helloPoint point/helloPoint.c)
add_executable(valueOfPoint point/valueOfPoint.c)
add_executable(castPoint point/castPoint.c)
add_executable(arrayAndPoint point/arrayAndPoint.c)
add_executable(pointArray point/pointArray.c)
add_executable(pointPoint point/pointPoint.c)
add_executable(StringAndPoint point/StringAndPoint.c)
add_executable(ArrayPoint point/ArrayPoint.c)
add_executable(FunctionAndPoint point/FunctionAndPoint.c)
add_executable(VoidPoint point/VoidPoint.c)
add_executable(PointOfNull point/PointOfNull.c)
add_executable(ParamOfMain point/ParamOfMain.c)
add_executable(Malloc memoryAllocation/MemoryAllocation.c)
add_executable(StringHandle string/StringHandle.c)
add_executable(Const variable/Const.c)
add_executable(Struct datatype/Struct.c)
add_executable(Enum datatype/Enum.c)
add_executable(Union datatype/Union.c)
add_executable(HelloLinkList linkList/HelloLinkList.c)
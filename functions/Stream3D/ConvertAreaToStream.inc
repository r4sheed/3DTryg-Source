Tryg3D::Function:: Stream:ConvertAreaToStream(STREAMER_TAG_AREA areaid){
	new StreamCreate(StreamData);
	if(!IsValidDynamicArea(STREAMER_TAG_AREA areaid)) return StreamData;
	switch(Streamer::GetIntData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_TYPE)){
		case STREAMER_AREA_TYPE_CIRCLE: {
			StreamData[T3D:type] = s_circle;
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_X,StreamData[T3D:X]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_Y,StreamData[T3D:Y]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_SIZE,StreamData[T3D:R]);
		}
		case STREAMER_AREA_TYPE_CYLINDER: {
			StreamData[T3D:type] = s_cylinder2d;
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_X,StreamData[T3D:X]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_Y,StreamData[T3D:Y]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MIN_Z,StreamData[T3D:minZ]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MAX_Z,StreamData[T3D:maxZ]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_SIZE,StreamData[T3D:R]);
		}
		case STREAMER_AREA_TYPE_SPHERE: {
			StreamData[T3D:type] = s_sphere;
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_X,StreamData[T3D:X]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_Y,StreamData[T3D:Y]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_Z,StreamData[T3D:Z]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_SIZE,StreamData[T3D:R]);
		}
		case STREAMER_AREA_TYPE_RECTANGLE: {
			StreamData[T3D:type] = s_rectangle;
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MIN_X,StreamData[T3D:minX]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MIN_Y,StreamData[T3D:minY]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MAX_X,StreamData[T3D:maxX]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MAX_Y,StreamData[T3D:maxY]);
		}
		case STREAMER_AREA_TYPE_CUBOID: {
			StreamData[T3D:type] = s_cube2d;
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MIN_X,StreamData[T3D:minX]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MIN_Y,StreamData[T3D:minY]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MIN_Z,StreamData[T3D:minZ]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MAX_X,StreamData[T3D:maxX]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MAX_Y,StreamData[T3D:maxY]);
			Streamer::GetFloatData(STREAMER_TYPE_AREA,_:areaid,E_STREAMER_MAX_Z,StreamData[T3D:maxZ]);
		}
	}
	return StreamData;
}
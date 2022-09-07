namespace IG {
    class difficultyBeatMap {
        public:
            std::string difficulty;
            int difficultyRank;
            std::string beatmapFilename;
            int noteJumpMovementSpeed;
            int noteJumpStartBeatOffset;
        difficultyBeatMap(std::string difficulty,int difficultyRank,std::string beatmapFilename,int noteJumpMovementSpeed,int noteJumpStartBeatOffset) : difficulty(difficulty), difficultyRank(difficultyRank), beatmapFilename(beatmapFilename), noteJumpMovementSpeed(noteJumpMovementSpeed), noteJumpStartBeatOffset(noteJumpStartBeatOffset) {}
    };
    class beatMapCharacteristic {
        public:
            std::string name;
            std::vector<difficultyBeatMap> difficultyBeatMaps;
        beatMapCharacteristic(std::string name,std::vector<difficultyBeatMap> difficultyBeatMaps) : name(name), difficultyBeatMaps(difficultyBeatMaps) {}
    };
    class beatMapcContainer {
        public:
        std::vector<IG::beatMapCharacteristic> beatMapCharacteristics;
    };

    inline Json::Value genDifficultyLevels(IG::beatMapcContainer BMC,bool FastWrite)
    {
        Json::Value DBM;
        Json::Value BMCa;
        for (int i = 0; i < BMC.beatMapCharacteristics.size(); i++) {
            for (int j = 0; j < BMC.beatMapCharacteristics[i].difficultyBeatMaps.size(); j++) {
                DBM["_difficulty"] = BMC.beatMapCharacteristics[i].difficultyBeatMaps[j].difficulty;
                DBM["_difficultyRank"] = BMC.beatMapCharacteristics[i].difficultyBeatMaps[j].difficultyRank;
                DBM["_beatmapFilename"] = BMC.beatMapCharacteristics[i].difficultyBeatMaps[j].beatmapFilename;
                DBM["_noteJumpMovementSpeed"] = BMC.beatMapCharacteristics[i].difficultyBeatMaps[j].noteJumpMovementSpeed;
                DBM["_noteJumpStartBeatOffset"] = BMC.beatMapCharacteristics[i].difficultyBeatMaps[j].noteJumpStartBeatOffset;
            }
            BMCa["_beatmapCharacteristicName"] = BMC.beatMapCharacteristics[i].name;
            BMCa["_difficultyBeatmaps"] = DBM;
        }
        return BMCa;

    }

    inline std::string genJson(IG::beatMapcContainer BMC,std::string songName, std::string songSubName, std::string songAuthorName, std::string levelAuthorName, float beatsPerMinute, float songTimeOffset, float shuffle, float shufflePeriod, float previewStartTime, float previewDuration, std::string songFilename, std::string coverImageFilename, std::string environmentName, std::string version, bool FastWrite)
    {
        Json::Value root;
        root["_version"] = version;
        root["_songName"] = songName;
        root["_songSubName"] = songSubName;
        root["_songAuthorName"] = songAuthorName;
        root["_levelAuthorName"] = levelAuthorName;
        root["_beatsPerMinute"] = beatsPerMinute;
        root["_songTimeOffset"] = songTimeOffset;
        root["_shuffle"] = shuffle;
        root["_shufflePeriod"] = shufflePeriod;
        root["_previewStartTime"] = previewStartTime;
        root["_previewDuration"] = previewDuration;
        root["_songFilename"] = songFilename;
        root["_coverImageFilename"] = coverImageFilename;
        root["_environmentName"] = environmentName;

        root["_difficultyBeatmapSets"] = Json::arrayValue

        root["_difficultyBeatmapSets"] = genDifficultyLevels(BMC, FastWrite);

        if (FastWrite)
        {
            Json::FastWriter writer;
            return writer.write(root);
        }
        else
        {
            Json::StyledWriter writer;
            return writer.write(root);
        }
    }
}



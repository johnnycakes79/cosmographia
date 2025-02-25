// This file is part of Cosmographia.
//
// Copyright (C) 2010-2011 Chris Laurel <claurel@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "WMSTiledMap.h"

using namespace vesta;
using namespace std;


WMSTiledMap::WMSTiledMap(TextureMapLoader* loader,
                         const QString& layerName,
                         unsigned int tileSize,
                         unsigned int levelCount) :
    HierarchicalTiledMap(loader, tileSize),
    m_levelCount(levelCount)
{
    m_tileNamePattern = QString("wms:") + layerName + ",%1,%2,%3";
}


string
WMSTiledMap::tileResourceIdentifier(unsigned int level, unsigned int column, unsigned int row)
{
    QString s = m_tileNamePattern.arg(level).arg(column).arg(row);
    return string(s.toUtf8().data());
}


bool
WMSTiledMap::isValidTileAddress(unsigned int level, unsigned int column, unsigned int row)
{
    return level < m_levelCount && column < (1u << (level + 1)) && row < (1u << level);
}


bool
WMSTiledMap::tileResourceExists(const std::string& /* resourceId */)
{
    return true;//level < levelCount;
}

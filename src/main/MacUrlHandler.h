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

#include <QObject>

class MacUrlHandler : public QObject
{
    Q_OBJECT

private:
    MacUrlHandler();

public:
    ~MacUrlHandler();
    static MacUrlHandler* Create();
    void handleUrl(const QString& url);

    QString lastUrl() const
    {
        return m_lastUrl;
    }

signals:
    void urlRequested(const QString& url);

private:
    class Private;

    Private* m_privateData;
    QString m_lastUrl;
};

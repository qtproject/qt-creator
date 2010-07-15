/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#ifndef FINDTOOLBAR_H
#define FINDTOOLBAR_H

#include "ui_findwidget.h"
#include "currentdocumentfind.h"

#include <utils/styledbar.h>

#include <QtCore/QTimer>

namespace Core {
class FindToolBarPlaceHolder;
}

namespace Find {
class FindPlugin;

namespace Internal {

class FindToolBar : public Utils::StyledBar
{
    Q_OBJECT

public:
    explicit FindToolBar(FindPlugin *plugin, CurrentDocumentFind *currentDocumentFind);
    ~FindToolBar();

    void readSettings();
    void writeSettings();

    void openFindToolBar();
    void setUseFakeVim(bool on);

public slots:
    void setBackward(bool backward);

private slots:
    void invokeFindNext();
    void invokeFindPrevious();
    void invokeFindStep();
    void invokeReplace();
    void invokeReplaceNext();
    void invokeReplacePrevious();
    void invokeReplaceStep();
    void invokeReplaceAll();
    void invokeResetIncrementalSearch();

    void invokeFindIncremental();
    void invokeFindEnter();
    void invokeReplaceEnter();
    void putSelectionToFindClipboard();
    void updateFromFindClipboard();

    void hideAndResetFocus();
    void openFind();
    void updateFindAction();
    void updateToolBar();
    void findFlagsChanged();

    void setCaseSensitive(bool sensitive);
    void setWholeWord(bool wholeOnly);
    void setRegularExpressions(bool regexp);

    void adaptToCandidate();

protected:
    bool focusNextPrevChild(bool next);

private:
    void installEventFilters();
    void invokeClearResults();
    bool setFocusToCurrentFindSupport();
    void setFindFlag(Find::FindFlag flag, bool enabled);
    bool hasFindFlag(Find::FindFlag flag);
    Find::FindFlags effectiveFindFlags();
    Core::FindToolBarPlaceHolder *findToolBarPlaceHolder() const;

    bool eventFilter(QObject *obj, QEvent *event);
    void setFindText(const QString &text);
    QString getFindText();
    QString getReplaceText();
    void selectFindText();
    void updateIcons();
    void updateFlagMenus();

    FindPlugin *m_plugin;
    CurrentDocumentFind *m_currentDocumentFind;
    Ui::FindWidget m_ui;
    QCompleter *m_findCompleter;
    QCompleter *m_replaceCompleter;
    QAction *m_findInDocumentAction;
    QAction *m_enterFindStringAction;
    QAction *m_findNextAction;
    QAction *m_findPreviousAction;
    QAction *m_replaceAction;
    QAction *m_replaceNextAction;
    QAction *m_replacePreviousAction;
    QAction *m_replaceAllAction;
    QAction *m_caseSensitiveAction;
    QAction *m_wholeWordAction;
    QAction *m_regularExpressionAction;
    Find::FindFlags m_findFlags;

    QPixmap m_casesensitiveIcon;
    QPixmap m_regexpIcon;
    QPixmap m_wholewordsIcon;

    QTimer m_findIncrementalTimer;
    QTimer m_findStepTimer;
    bool m_useFakeVim;
    bool m_eventFiltersInstalled;
};

} // namespace Internal
} // namespace Find

#endif // FINDTOOLBAR_H

set(TSTFLAMEGRAPHVIEW_CPP_SOURCES
  testflamegraphmodel.h
  tst_flamegraphview.cpp
)

if(${Qt5_VERSION} VERSION_LESS "6.2.0")
  add_qtc_test(tst_tracing_flamegraphview
    DEPENDS Tracing Qt5::QuickWidgets Qt5::Quick Utils
    SOURCES
      ${TSTFLAMEGRAPHVIEW_CPP_SOURCES}
      flamegraphview.qrc
  )
else() # < Qt 6.2
  add_qtc_test(tst_tracing_flamegraphview
    DEPENDS Tracing Qt5::QuickWidgets Qt5::Quick Utils
  )

  qt_add_qml_module(tst_tracing_flamegraphview
    URI "QtCreator.TstTracingFlameGraphView"
    VERSION "1.0"
    NO_CREATE_PLUGIN_TARGET
    QML_FILES
      TestFlameGraphView.qml
    SOURCES
      ${TSTFLAMEGRAPHVIEW_CPP_SOURCES}
  )
endif() # < Qt 6.2

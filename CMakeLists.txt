project(plasma-rssnotify)
find_package(KDE4 REQUIRED)
#include(KDE4Defaults) #extra
#find_package(Plasma REQUIRED) #extra


add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}  ${KDE4_INCLUDES})

set(news_SRCS
    news.cpp
    scroller.cpp
)

kde4_add_ui_files(news_SRCS config.ui)

kde4_add_plugin(plasma_applet_rssnotify ${news_SRCS})
target_link_libraries(plasma_applet_rssnotify ${KDE4_PLASMA_LIBS} ${KDE4_KIO_LIBS} ${KDE4_KDEUI_LIBS})

install(TARGETS plasma_applet_rssnotify DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasma-applet-rssnotify.desktop DESTINATION ${SERVICES_INSTALL_DIR})
#install(FILES feeds DESTINATION ${DATA_INSTALL_DIR}/rssnotify)
#install(FILES svg/rssnotify.svgz DESTINATION ${DATA_INSTALL_DIR}/desktoptheme/default/rssnotify/)

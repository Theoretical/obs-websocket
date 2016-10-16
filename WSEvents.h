#ifndef WSEVENTS_H
#define WSEVENTS_H

#include <QtWebSockets/QWebSocket>
#include <QTimer>
#include <obs-frontend-api.h>
#include <util/platform.h>
#include "WSServer.h"

class WSEvents : public QObject 
{
	Q_OBJECT

	public:
		explicit WSEvents(WSServer *server);
		~WSEvents();
		static void FrontendEventHandler(enum obs_frontend_event event, void *private_data);

	private Q_SLOTS:
		void StreamStatus();

	private:
		WSServer *_srv;
		uint64_t _streamStartTime;
		uint64_t _lastBytesSent;
		uint64_t _lastBytesSentTime;
		void broadcastUpdate(const char *updateType, obs_data_t *additionalFields);

		void OnSceneChange();
		void OnSceneListChange();

		void OnStreamStarting();
		void OnStreamStarted();
		void OnStreamStopping();
		void OnStreamStopped();

		void OnRecordingStarting();
		void OnRecordingStarted();
		void OnRecordingStopping();
		void OnRecordingStopped();

		void OnExit();
};

#endif // WSEVENTS_H